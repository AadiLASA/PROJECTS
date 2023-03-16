//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 *	Linked List lab.
 *	- Build a library for singly linked list.
 *	- Replace the airport array in main with a Linked List.
 *  - sort the array. 
 *	
 */


#include <iostream>
#include <fstream>
#include <cmath> 
#include "slist.cpp"
using namespace std;





void simpleSortTotal(linked_list* s, int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[1000] ;
   linked_list* airportArr = new linked_list();		
    linked_list* within100 = new linked_list();	// Replace array with Linked List
    int   airportCount=0;
    //Airport* a[13500];
     Airport* air=new Airport();
        Airport* last=new Airport();
    infile.open ("airport-codes_US.csv", ifstream::in);
    if (infile.is_open())
    {
        Airport* chiefBeefAirspace = new Airport();
        
        int   c=0;
       // int count = 0;
        infile.getline(cNum, 256, '\n');
        while (infile.good())
        {
         //   count++;
            infile.getline(chiefBeefAirspace->code, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            infile.getline(cNum, 256, ',');
            chiefBeefAirspace->longitude = atof(cNum);
            infile.getline(cNum, 256, ',');
            chiefBeefAirspace->latitude = atof(cNum);
           airportArr->add_node(*chiefBeefAirspace);
            infile.getline(cNum, 256, '\n');
           //if (!(c % 1000))
             /*  cout << chiefBeefAirspace->code << " long: " << chiefBeefAirspace->longitude << " lat: " << chiefBeefAirspace->latitude <<  endl;
            */

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }

        // cout << airportArr->getNode(0)->data.longitude << endl;
      
        airportCount = c-1;
        infile.close();
       simpleSortTotal(airportArr,airportCount);
        for (int b =0; b<c; b++){
            cout << airportArr->getNode(b)->data.code << " long: " << airportArr->getNode(b)->data.longitude << " lat: " << airportArr->getNode(b)->data.latitude << "  total   - " << distanceEarth(97.7449757, 30.27104167, airportArr->getNode(b)->data.latitude, airportArr->getNode(b)->data.longitude)*0.621371 << endl;
        if (distanceEarth(97.7449757, 30.27104167, airportArr->getNode(b)->data.latitude, airportArr->getNode(b)->data.longitude)*0.621371 <= 100){
        air = &airportArr->getNode(b)->data;
        within100->add_node(*air);
        }
            if ((b + 1) == c){
            last = &airportArr->getNode(b)->data;
            }
        }

         /*for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }
*/


    }
    else
    {
        cout << "Error opening file";
    }
 

cout << "All airports within a 100 miles of the reference point: " << within100->toString()<<endl;
cout << "Airport farthest from AUS is: " << last->code << " at " << distanceEarth(97.7449757, 30.27104167, last->latitude, last->longitude)*0.621371 << endl;    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void simpleSortTotal( linked_list* arg , int c)
{

   
    double maxDistance = 0;
    string max;
    for (int i = 0; i < 22338; i++) {
      //97.7449757, 30.27104167
        double distance = distanceEarth(30.27104167, -97.7449757,  arg->getNode(i)->data.latitude, arg->getNode(i)->data.longitude);
        //cout << distance << endl;
        if (distance < 160.934) {
             cout << arg->getNode(i)->data.code << " " << distance / 1.609 << endl;
        }
        if (distance > maxDistance) {
            maxDistance = distance;
            max = arg->getNode(i)->data.code;
        }
       
        
    }

    cout << "Max airport " << max << " " << maxDistance << endl;
    
    
	Airport k;
	for (int i=0; i < c; i++){
		for (int j=i; j <= c; j++){
		if (distanceEarth(97.7449757, 30.27104167, arg->getNode(i)->data.latitude, arg->getNode(i)->data.longitude) < distanceEarth(97.7449757, 30.27104167, arg->getNode(j)->data.latitude, arg->getNode(j)->data.longitude))
		{
                arg->swap(i,j);   
            
		}
        }
        
        }



    
    
} 