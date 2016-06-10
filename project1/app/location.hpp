#ifndef LOCATION_HPP
#define LOCATION_HPP

struct location
{
    double lat, lon, distance;
    std::string lat_dir, lon_dir, description;
};


unsigned int get_number_of_location();
double deg2rad(double deg);
std::tuple<double, double> format_lat_lon(location l);
double calculate_distance(location start, location end);
location get_location();
std::string double2string(double x);
std::string print_location(location l);

#endif // LOCATION_HPP