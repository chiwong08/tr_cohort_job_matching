#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct res{
    string jobSpec;		// the job spec,
    string individual;		// the individual
    int numSpecs;		// the first int is number of specs attached to job spec
    int matchSpecs;		// the second int is the number of matches of specs
    double percentagematch;	// the double is % match
};


vector<string> match( vector<string> jobspecs, vector<string> individuals )
{
    vector<res> result;		

    for (int i=0; i < jobspecs.size(); ++i)
    {
        string theJob = "Job " + i;		// give this job a unique reference e.g. job 1, job 2 ...
        string theSpec = jobspecs[i];
        int numspecs = jobspecs.size();		// number of specs for this job

        result[i].jobSpec = theJob;
        result[i].numSpecs = numspecs;
        result[i].matchSpecs = 0;

        for ( int j = 0; i < individuals.size(); ++j )		// now loop individuals to see what skills they match
        {
            string theInd = "individual" + j;
            result[i].individual =  theInd;
            string indSkill = individuals[j];
            size_t found = indSkill.find(theSpec);
            if ( found!=string::npos )
            {
                result[i].matchSpecs +=1;
                result[i].percentagematch = result[i].matchSpecs / result[i].numSpecs;
            }
        }
    }
    return result;
}



int main()
{
    vector<string> jobchars = {'"remote" "flexible working hours" "summit api"', '"office based two days per week" "react developer"'};
    vector<string> individualskills = {'"wants to work remote" "react experience" "looking for frontend"', '"backend developer" "cloud experience" "AWS certified"'};

    vector<res> results = match(jobchars, individualskills);

    for (int i = 0; i < results.size(); ++i )
    {
        cout << "Job " << res[i].jobSpec << ", Individual " << res[i].individual << " found " << res[i].matchSpecs << " matching skills from " << res[i].numSpecs << ", which equates to " << (res[i].percentagematch *100) << "%" << endl;
    }

    // technically, should run the above in a try-catch block to catch any errors so, but due to time constraints..
    // and too much time spent thinking about how to do it ...

    return 0;
}
