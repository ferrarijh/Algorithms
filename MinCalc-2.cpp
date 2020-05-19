#include <vector>
#include <string>
#include <list>
#include <iostream>
using namespace std;
/*Calculate the smallest number you can get by putting any number of parenthesis between numbers.
INPUT : string equation
OUTPUT : smallest number
*/

int main() {
	string str;
	cin >> str;
	int sz = (int)str.size();
	vector<int> nums;
	vector<char> ops;
	string temp_str;
	for (int i = 0; i < sz; i++) {
		if (str[i] == '+' || str[i] == '-') {
			ops.push_back(str[i]);
			continue;
		}
		temp_str = "";
		while (str[i] != '+' && str[i] != '-') {	//str[str.size()] 는 NULL char 반환함.
			temp_str += str[i++];
			if (i == sz)
				break;
		}
		i--;
		nums.push_back(stoi(temp_str));
	}
	int i = 0;
	while (i < (int)ops.size()) {
		if (ops[i] == '+') {
			nums[i] += nums[i + 1];
			nums.erase(nums.begin() + i + 1);
			ops.erase(ops.begin() + (i--));		//i--
		}
		i++;
	}
	int res = nums[0];
	for (int i = 1; i < (int)nums.size(); i++)
		res -= nums[i];
	cout << res;

	return 0;
}

/*=====test input=====
55-50+40
>>answer : -35
*/