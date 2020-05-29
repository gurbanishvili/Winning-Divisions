#include <iostream>
using namespace std;

const string north_east_division = "North East",
             north_west_division = "North West",
             south_east_division = "South East",
             south_west_division = "South West";

double getSales(string division){
    string checker_str;
    double checker_dbl;
    cout << "Enter the quarterly sales for the " << division << " division: " << endl;
    cin >> checker_str;

    while (true) {
      try {
        checker_dbl = stod(checker_str);

        if (checker_dbl >= 0) {
          cout << "Your input of " << checker_dbl << " was valid." << endl; 
          break;
        }
        cout << "Input must be greater than or equal to zero. Try again: " << endl;
      }
      catch (invalid_argument e) {
        cout << "Input must be a double. Try again: " << endl;
      }

      cin >> checker_str;
    }
    return checker_dbl;
}

void findHighest(double north_east_sales,
                 double north_west_sales,
                 double south_east_sales,
                 double south_west_sales)
// The findHighest function will accept four double arguments
{
    double assumed_highest = north_east_sales;
    string final_highest = "North East Division";

    if (assumed_highest < north_west_sales){
        assumed_highest = north_west_sales;
        final_highest = "North West Division";
    }
        if (assumed_highest < south_east_sales){
            assumed_highest = south_east_sales;
            final_highest = "South East Division";
        }
            if (assumed_highest < south_west_sales){
                assumed_highest = south_west_sales;
                final_highest = "South West Division";
            }

    cout << "The division with the highest quarterly sales is the following: " << final_highest << endl;
}

int main()
{
  double north_east_sales,
         north_west_sales,
         south_east_sales,
         south_west_sales;
        
  north_east_sales = getSales(north_east_division);
  north_west_sales = getSales(north_west_division);
  south_east_sales = getSales(south_east_division);
  south_west_sales = getSales(south_west_division);

  findHighest(north_east_sales, north_west_sales, south_east_sales, south_west_sales);

  return 0;
}