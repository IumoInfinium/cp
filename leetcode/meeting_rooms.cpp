// Given an array of meeting time intervals consisting of start and end times[[s1,e1],[s2,e2],...](si< ei), determine if a person could attend all meetings.

#include <bits/stdc++.h>
using namespace std;

bool meetingRoom(vector<vector<int>> intervals){
		bool ans=true;
		sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>&b){
				return a[0] < b[0];
				});
		int n = intervals.size();
		for(int i=1; i<n; i++) {
				if(intervals[i-1][1]>= intervals[i][0]) return false;
		}
		return true;
}
int main()
{
		vector<vector<int>> timeIntervals= {{0,30}, {5,10}, {15,20}};
		vector<vector<int>> timeIntervals1 = {{7,10}, {2,4}};
		bool result = meetingRoom(timeIntervals1);
		cout << "Meeting Possible :" << result << endl; 
		return 0;
}
