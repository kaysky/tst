#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>
#include <stdexcept>

using namespace std;

struct contr
{
	double Lon;
	double Lat;

	contr(const string& lo, const string& la)
	{
		Lon = get_lonlat(lo);
		Lat = get_lonlat(la);
	}

	pair<double,string> parse_str(const string& str)
	{
		stringstream ss(str);
		string tmp;
		string name;
		string dLon;
		string dLat;
		double dst;

		getline(ss,tmp,';'); /// number of defib-or
		//cout << tmp << endl;
		getline(ss,name,';'); /// name of org
		//cout << tmp << endl;
		getline(ss,tmp,';'); // addres of def-or
		//cout << tmp << endl;
		getline(ss,tmp,';'); // phone of def-or
		//cout << tmp << endl;
		getline(ss,dLon,';'); // longitude
		//ut << dLon << endl;
		getline(ss,dLat,';'); // latitude
		//cout << dLat << endl;

		dst = count_dst(dLon,dLat);
		return make_pair(dst,name);
	}

	double get_lonlat(const string& str)
	{
		try
		{
			string tmp(str);
			size_t pos = tmp.find(',');
			if(pos != string::npos)
				tmp.replace(pos,1,".");
			//cout << tmp << endl;
			return stod(tmp);
		}
		catch(invalid_argument &ex)
		{
			cout << "wrong value for stood" << endl;
		}
		return 0.0;
	}

	double count_dst(const string& lon, const string& lat)
	{
		double dlon = get_lonlat(lon);
		double dlat = get_lonlat(lat);
		double x = (dlon - Lon) * cos((Lat + dlat)/2);
		double y = dlat -Lat;
		double d = sqrt( (x*x) + (y*y) ) * 6371;
		return d;
	}

};

typedef pair<double,string> pr;
struct first_cm
{
	bool operator()(const pr& left, const pr& right)
	{
		return left.first < right.first;
	}
};

int main(int argc, char *argv[])
{
	std::cout << "test of parsing strings" << std::endl;

	map<double,string> dbase;
	string lon;
	string lat;
	string N;
	string tmp;
	ifstream in("in2.txt");

	if(in.is_open())
	{
		in >> lon;
		in >> lat;
		in >> N;
		contr dst(lon,lat);
//		cout << dst.Lon << "/" << dst.Lat << endl;
		while(getline(in,tmp))
		{
			dbase.insert(dst.parse_str(tmp));
		}

		pr closest = *min_element(dbase.begin(),dbase.end(),first_cm());
		cout << "closet def-or: " << closest.second << endl;
//		string l1("45,454554");
//		string l2("4,454554");
//		string l3("5,454554");
//		string l4("4588,454554");
//		string l5("0,54");
//		cout << dst.get_lonlat(l1) << endl;
//		cout << dst.get_lonlat(l2) << endl;
//		cout << dst.get_lonlat(l3) << endl;
//		cout << dst.get_lonlat(l4) << endl;
//		cout << dst.get_lonlat(l5) << endl;
	}
	else
		std::cout << "error open file" << std::endl;

	std::cout << "end of the test." << std::endl;

	return 0;
}
