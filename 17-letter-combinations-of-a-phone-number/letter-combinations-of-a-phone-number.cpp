class Solution {
public:
    void f(string& digits, int index, string& combination, vector<string>& mapping, vector<string>& result) 
{

    // Base case: If we have processed all digits, add the current combination to the result.
    if(digits.size()==0)
        return;
    if (index == digits.length()) 
    {
        result.push_back(combination);
        return;
    }

    // Get the letters corresponding to the current digit.
    string letters = mapping[digits[index] - '0'];

    // Iterate over the letters and generate combinations.

    for (char letter : letters) 
    {
        combination += letter;
        f(digits, index + 1, combination , mapping, result);
        combination.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
       // Mapping of digits to letters.
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    // Result vector to store the generated combinations.
    vector<string> result;
    string combination;
    // Call the recursive function to generate combinations.
    f(digits, 0, combination, mapping, result);
    // Return the result vector containing the generated combinations.
    return result;
    }
};