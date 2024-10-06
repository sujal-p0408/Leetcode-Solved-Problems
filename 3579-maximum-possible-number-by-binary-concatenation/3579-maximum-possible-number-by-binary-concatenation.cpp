class Solution {
public:

   string decimalToBinary(int number) {
        if (number == 0) {
            return "0";
        }
        string binary = "";
        while (number > 0) {
            binary = to_string(number % 2) + binary;
            number /= 2;
        }
        return binary;
    }

    int binaryToDecimal(const string& binary) {
        int decimal = 0;
        for (char bit : binary) {
            decimal = decimal * 2 + (bit - '0');  // More efficient than using pow
        }
        return decimal;
    }

    int maxGoodNumber(vector<int>& nums) {
       
        vector<string> binaries;
        for (int num : nums) {
            binaries.push_back(decimalToBinary(num));
        }

        
        int maxValue = 0;
        sort(binaries.begin(), binaries.end());
        do {
            string concatenated = binaries[0] + binaries[1] + binaries[2];
            maxValue = max(maxValue, binaryToDecimal(concatenated));
        } while (next_permutation(binaries.begin(), binaries.end()));

        return maxValue;
    }

};