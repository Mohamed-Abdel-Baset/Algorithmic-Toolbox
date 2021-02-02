#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
 /*
This code uses greedy algorithm to calculate min number of refills needed for a car to go
 from start point A to end point B with multiple number of stops for gas stations.
 This code is among week 3 assignments of Algorithmic toolbox course on coursera.
 */

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int g = stops.size()-2; //number of gas stations
    int current_refill = 0; //contains the index of current stop. initially it is at start point (index = 0)
    int refills = 0;  //contains number of refills - the answer

    //external while loop, exits when reaching end point "B"
    while(current_refill <= g){  //current_refill should be at most = g
        int last_refill = current_refill;  //contains the index of last stop for refilling.
        // loop to reach farthest reachable stop :
        while(current_refill<=g && ((stops[current_refill+1]-stops[last_refill]) <= dist)){
            current_refill++;
        }
        //if distance between 2 stops is larger than dist, return -1(impossible)
        if (current_refill == last_refill){
            return -1;
        }
        //increment refills
        if (current_refill <= g){
            refills++;
            //cout<<current_refill<<"\n";
        }
    }
    return refills;
}


int main() {
    int d = 0; //input maximum distance the car can travel with full tank
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0; //input number of stops during the trip -start and end points included-
    cin >> n;

    vector<int> stops(n); //vector of integers contains start, end and gas stations stops
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
