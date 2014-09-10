#pragma once

#include "Helper.h"

using namespace std;

void SolveQueryProblem(string filei, string file)
{
	StringList_t q;
	StringList_t realGoddamnMotherfuckingQueries;
	StringList_t body;
	int i = 0;
	for_e(a, parseFile(filei))
	{
		if(i%2 == 0 && i != 0)
		{
			body.pb(toUpper(a));
		}
		if(i%2 != 0)
		{
			q.pb(removeAllChar(toUpper(a),' '));
			realGoddamnMotherfuckingQueries.pb(toUpper(a));
		}
		i++;
	}
	for(int i = 0; i < body.size(); i++)
	{
		if( i == 5 )
			int testmotherfucker = 5;

		auto b = body[i];

		bool isGood = false;
		StringList_t bodytext = splitString(b,' ');
		StringList_t bodywords = splitString(b,' ');
		int iterations = bodywords.size();

		for (int o = 0; o < iterations; o++)
		{
			string tosearch;
			string searchthis = q[i];
			for_e( w, bodywords )
			{
				tosearch += w;
			}
			if(strncmp(tosearch.c_str(), searchthis.c_str(), searchthis.size()) == 0)
			{
				isGood = true;
				break;
			}
			bodywords.erase(bodywords.begin());
		}

		string testme = realGoddamnMotherfuckingQueries[i];

		if(isGood)
		{
			for_e(word, bodytext)
			{
				for (int z = 0; z < word.size(); z++)
				{
					removeString(testme,word);
					word.pop_back();
					z = 0;
				}
			}

			removeAllChar(testme,' ');

			if( testme.size() > 0 )
				isGood = false;
		}

		if(isGood)
		//	f::w("true\n", fileo);
			printf("true\n");
		else
			printf("false\n");
		//	f::w("false\n", fileo);
	}
}