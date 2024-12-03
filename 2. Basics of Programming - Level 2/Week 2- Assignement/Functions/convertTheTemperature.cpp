#include<iostream>
#include<vector>
using namespace std;
vector<double> convertTheTemperature(double celsius){
    vector<double> arr;
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;
    arr.push_back(kelvin);
    arr.push_back(fahrenheit);
    return arr;
}
int main(){
    double celsius;
    cout << "Enter the celsius: ";
    cin >> celsius;
    vector<double> ans = convertTheTemperature(celsius);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
}