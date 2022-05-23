#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int tape_size=8;
    char tape[tape_size]={'#', '0', '0', '1', '0', '1', '1', '#'};
    int start_poz=3;
    int start_rule=0;
    //vector<vector<vector<char>>> rules = {{}};
    char alph[] = { '0','1', '#'};
    // 2-kolichestvo pravil, 3-kol peremen(alph), 3-(na sho zamenit, kuda idti, kakoe pravilo isp)
    char rules[2][3][3]=
            {
            {{'1','l','0'},{'0','l','0'},{'1','r','1'}},
            {{'0','r','1'},{'1','r','1'},{'#',0,'2'}}
            };
    for(auto const& value : tape)
        cout << value << ";";
    cout << endl;

    while (start_rule < (sizeof(rules)/ sizeof(rules[1])) )
    {
        int i;
        for (i = 0; i < sizeof(tape)/ sizeof(tape[1]);i++){
            if(tape[start_poz]==alph[i])break;
        }
        tape[start_poz]= rules[start_rule][i][0];
        if (rules[start_rule][i][1] == 'l') start_poz -= 1;
        else if (rules[start_rule][i][1] == 'r') start_poz += 1;
        start_rule = (int)rules[start_rule][i][2] - 48;

        for(auto const& value : tape)
            cout << value << ";";
        cout << endl;
    }

    return 0;
}
