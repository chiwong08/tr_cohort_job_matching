#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct jobSpecs
{
    vector<string> specs;
};

struct candidateSkills
{
    vector<string> skills;
};

struct results
{
    string candidateNum;
    string jobNum;
    int numJobSpecs;
    int numMatches;
    double pctMatch;
};

vector<results> match( vector<jobSpecs> aJobs, vector<candidateSkills> aCands )
{
    vector<results> theRes;
    stringstream ss, ss2;
    for (int i = 0; i < aJobs.size(); ++i )
    {
        jobSpecs aSpecs = aJobs[i];
        int njs = 0;

        ss.str("");
        ss << "Job_" << i+1;

//cout << "Job " << i << " specs -> ";
        for (int j=0; j < aSpecs.specs.size(); ++j )
        {
            njs = aSpecs.specs.size();
            string theSpec = aSpecs.specs[j];
//cout << theSpec << ", " ;
        int jobmatches = 0;
        double pctMatch = 0.0;
            for (int p = 0; p < aCands.size(); ++p )
            {
                results ares;
                ares.jobNum = ss.str();
                ares.numJobSpecs = njs;
                ares.numMatches = 0;
                ares.pctMatch = 0.0;
                ss2.str("");
                ss2 << "Candidate_" << p+1;
    cout << "\t" << "Candid8 # " << ss2.str() << endl;
                ares.candidateNum = ss2.str();
                candidateSkills acandid8 = aCands[p];
                for (int q = 0; q < acandid8.skills.size(); ++q)
                {
                    string theSkill = acandid8.skills[q];
    cout << "\tSkill read in *" << theSkill << endl;
    cout << "jobSpec = " << theSpec << endl;
                    if ( theSpec.find(theSkill) != string::npos )
                    {
    cout << "into match" << endl;
                        ares.numMatches++;
                        ares.pctMatch = double(ares.numMatches) / double(ares.numJobSpecs);
                    }
                }
                theRes.push_back(ares);
            }
        }
//cout << "** end of specs" << endl;
cout << endl;

    }
    return theRes;
}



int main ()
{
    vector<jobSpecs> allJobs;
    vector<candidateSkills> allCandidates;

    jobSpecs jsA;
    jsA.specs.push_back("remote");
    jsA.specs.push_back("flexible working hours");

    jobSpecs jsB;
    jsB.specs.push_back("office based two days per week");
    jsB.specs.push_back("react developer");

    candidateSkills cs1;
    cs1.skills.push_back("wants to work remote");
    cs1.skills.push_back("react experience");
    cs1.skills.push_back("looking for frontend");

    candidateSkills cs2;
    cs2.skills.push_back("backend developer");
    cs2.skills.push_back("cloud experience");
    cs2.skills.push_back("AWS certified");
    cs2.skills.push_back("remote");

    allJobs.push_back( jsA );
    allJobs.push_back( jsB );

    allCandidates.push_back( cs1 );
    allCandidates.push_back( cs2 );

    vector<results> theResults = match( allJobs, allCandidates );

    // Now that we have checked all job specs against all candidates we can report 
    // for this jobspec and the matches, if any, from the candidates
    for (int q = 0; q < theResults.size(); ++q)
    {
        results printRes = theResults[q];
        cout << printRes.jobNum << " - " << printRes.candidateNum << " - matched " << printRes.numMatches << " out of " << printRes.numJobSpecs << " - giving a " << int(printRes.pctMatch * 100) << "% match" << endl;
    }

    return 0;
}
//struct results
//{
//    string candidateNum;
//    string jobNum;
//    int numJobSpecs;
//    int numMatches;
//    double pctMatch;
//};
