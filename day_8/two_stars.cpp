#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <istream>
#include <iterator>
#include <cmath>


int find_diff(std::string first,std::string second) {
    std::vector<char> diff;
    int arr[7] = { 0 };
    //0 1 2 3 4 5 6
    //a b c d e f g
    for (int i = 0; i < first.size(); i++) {
        int smf = first[i]-'a';
        arr[smf]++;
    }
    for (int i = 0; i < second.size(); i++) {
        int smf = second[i] - 'a';
        arr[smf]++;
    }
    for (int i = 0; i < 7; i++) {
        if (arr[i] == 1) {
            diff.push_back(i + 'a');
        }
    }
    int size=diff.size();
    return size;
}
int compare(std::string first,std::string second){
    std::vector<char> diff;
    int arr[7] = { 0 };
    //0 1 2 3 4 5 6
    //a b c d e f g
    for (int i = 0; i < first.size(); i++) {
        int smf = first[i]-'a';
        arr[smf]++;
    }
    for (int i = 0; i < second.size(); i++) {
        int smf = second[i] - 'a';
        arr[smf]++;
    }
    for (int i = 0; i < 7; i++) {
        if (arr[i] == 1) {
            return 0;
        }
    }
    return 1;
}
int main() {


    std::ifstream file("D:\\CLion_2021.2.1\\MyProjects\\EVM7\\in.txt");
    std::string line;
    int count_of_numbers[10]={0};
    int sum=0;
    while (getline(file, line)) {


        std::istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        std::vector<std::string> numbers_temp;
        for (int i = 0; i < 10; i++) {
            numbers_temp.push_back(arrayTokens[i]);
        }
        std::vector<std::string> numbers;
        for(int i=0;i<10;i++){
            numbers.push_back("-1");
        }

        for (int i = 0; i < 10; i++) {
            if (numbers_temp[i].size() == 2) {
                numbers[1] = numbers_temp[i];
            }
            if (numbers_temp[i].size() == 3) {
                numbers[7] = numbers_temp[i];
            }
            if (numbers_temp[i].size() == 7) {
                numbers[8] = numbers_temp[i];
            }
            if (numbers_temp[i].size() == 4) {
                numbers[4] = numbers_temp[i];
            }
        }
        //690
        std::vector<std::string> temp_690;
        for(int i=0;i<10;i++){
            if(numbers_temp[i].size()==6){
                temp_690.push_back(numbers_temp[i]);
            }
        }
        int need_delete=0;
        for(int i=0;i<3;i++){
            int size=find_diff(numbers[4],temp_690[i]);\
            if(size==2) {
                numbers[9] = temp_690[i];
                need_delete=i;

            }
        }
        temp_690.erase(temp_690.begin()+need_delete);
        for(int i=0;i<2;i++){
            int size=find_diff(numbers[7],temp_690[i]);\
            if(size==5) numbers[6] = temp_690[i];
            if(size==3) numbers[0] = temp_690[i];
        }
        //235
        std::vector<std::string> temp_235;
        for(int i=0;i<10;i++){
            if(numbers_temp[i].size()==5){
                temp_235.push_back(numbers_temp[i]);
            }
        }
        for(int i=0;i<3;i++){
            int size=find_diff(numbers[1],temp_235[i]);\
            if(size==3) {
                numbers[3] = temp_235[i];
                need_delete=i;

            }
        }
        temp_235.erase(temp_235.begin()+need_delete);
        for(int i=0;i<2;i++){
            int size=find_diff(numbers[6],temp_235[i]);\
            if(size==1) numbers[5] = temp_235[i];
            if(size==3) numbers[2] = temp_235[i];
        }
        int number_int=0;
        for(int i=0;i<4;i++){
            std::string curr_number=arrayTokens[11+i];
            for(int j=0;j<10;j++) {
                if (compare(curr_number, numbers[j])) {
                    number_int *= 10;
                    number_int += j;
                }
            }
        }
        sum+=number_int;


    }
    return sum;
}
