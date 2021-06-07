#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    std::string line;
    vector <string> res_s = {"1_test_res.txt", "2_test_res.txt", "3_test_res.txt", "4_test_res.txt", "5_test_res.txt", "6_test_res.txt", "7_test_res.txt", "8_test_res.txt", "9_test_res.txt", "10_test_res.txt"};
    vector <string> res_it(10);
    for (int i = 0; i < 10; i++){
        std::ifstream in(res_s[i]);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                res_it[i] = line;
            }
        }
        in.close();
    }
    std::ofstream ofs;
    vector <string> out_s = {"1_test_out.txt", "2_test_out.txt", "3_test_out.txt", "4_test_out.txt", "5_test_out.txt", "6_test_out.txt", "7_test_out.txt", "8_test_out.txt", "9_test_out.txt", "10_test_out.txt"};
    vector <string> out_it(10);
    for (int i = 0; i < 10; i++){
        std::ifstream in(out_s[i]);
        if (in.is_open())
        {
            while (getline(in, line))
            {
                out_it[i] = line;
            }
        }
        in.close();
        ofs.open(out_s[i], std::ofstream::out | std::ofstream::trunc);
        ofs.close();
    }
    int res = 0;
    for (int i = 0; i < 10; i++){
        if (out_it[i] == res_it[i]) res ++;
        else cout << "Test " << i+1 << ": Wrong answer" << endl; 
    }
    cout << "Successfully Completed: " << res << endl;


    return 0;
}