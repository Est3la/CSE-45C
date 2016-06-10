#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

#include "location.hpp"

const double pi = 3.14159265358979323846;
const double Radius = 3959.9;


unsigned int get_number_of_location()
{
    unsigned int i;
    std::cin >> i;

    std::string temp;
    std::getline(std::cin, temp);
    
    return i;
}

double deg2rad(double deg)
{
    return deg*pi/180;
}

std::tuple<double, double> format_lat_lon(location l)
{
    if (l.lat_dir == "/S") l.lat = -l.lat;
    if (l.lon_dir == "/W") l.lon = -l.lon;
    return std::make_tuple(deg2rad(l.lat), deg2rad(l.lon));
}

double calculate_distance(location start, location end)
{
    double lat1r, lon1r, lat2r, lon2r;
 
    std::tie(lat1r, lon1r) = format_lat_lon(start);
    std::tie(lat2r, lon2r) = format_lat_lon(end);

    double dlat = lat2r - lat1r;
    double dlon = lon2r - lon1r;
    
    double a = pow(sin(dlat/2),2) + cos(lat1r) * cos(lat2r) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    return  Radius * c;
}

location get_location()
{
    location l;
    std::cin >> l.lat >> l.lat_dir >> l.lon >> l.lon_dir;
    std::cin.ignore(1);
    std::getline(std::cin, l.description);
    return l;
}

std::string double2string(double x)
{
    std::ostringstream s;
    s << x;
    return s.str();
}

std::string print_location(location l)
{
    std::string result = "";
    result += double2string(l.lat) + l.lat_dir + " "
            + double2string(l.lon) + l.lon_dir + " "
            + "(" + l.description + ")";
    
    if (l.distance == 0) result += "\n";
    else result += " (" + double2string(l.distance) + " miles)\n";
    return result;
}
