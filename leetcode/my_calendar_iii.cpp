// class MyCalendarThree {
// public:
//     unordered_map<int,pair<int,int>> map;
//     MyCalendarThree() {
//     }
    
//     int book(int start, int end) {
//         int res=1;
//         if(map.size()==0){
//             map[start]={end,1};
//             cout<<"1st ele\n";
//             return 1;
//         }
//         bool f=false;
//         for(auto it=map.begin();it!=map.end();it++){
//             if(start>=it->first || (start>it->first && end<it->second.first)){
//                 map[start]={(it->second.first > end ? it->second.first : end),it->second.second+1};
//                 cout<<it->first <<"   "<<it->second.first<<"--->"<<it->second.second<<"\n";
//                 return it->second.second;
//             }
//         }
//         if(!f){
//             map[start]={end,1};
//             cout<<start<<"   "<<end<<"--->"<<1<<" new \n";
//             return 1;
//         }
        
//         return 0;
//     }
// };

class MyCalendarThree{
public:
    int maxBookings=0;
    map<int,int> m;
        
    MyCalendarThree(){
    }
    
    int book(int start,int end){
        m[start]++;
        m[end]--;
        int bookings=0, summ=0;
        for(auto it=m.begin(); it!=m.end(); it++){
            bookings += it->second;
            maxBookings = max(maxBookings,bookings);
        }
        return maxBookings;
    }
};


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
