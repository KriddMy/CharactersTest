#include <iostream>
#include <algorithm>

using namespace std;

const char g_UniqueChatacterSign = '(';
const char g_UnuniqueChatacterSign = ')';
const char g_DifferanceBetweenSigns = g_UnuniqueChatacterSign - g_UniqueChatacterSign;

int main()
{
    string inputString;
    cin >> inputString;
    //перевожу строку в lowercase
    transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);

    //массив флагов, отражающий была ли проверенна данная переменная
    bool* checkedFlags = new bool[inputString.size()];
    memset(checkedFlags, 0, inputString.size());
    
    int firstLoopIndex = 0;
    for (auto i = inputString.begin(); i < inputString.end(); i++, firstLoopIndex++)
    {
        //если символ уже был проверен - пропускаем
        if (checkedFlags[firstLoopIndex])
            continue;

        char flag = 0;
        int secondLoopIndex = firstLoopIndex + 1;
        for (auto j = i + 1; j < inputString.end(); j++, secondLoopIndex++)
        {
            if (*i == *j)
            {
                flag = 1;
                checkedFlags[secondLoopIndex] = true;
                *j = g_UnuniqueChatacterSign;
            }

        }
        //флаг - чтобы не использовать оператор if
        *i = g_UniqueChatacterSign + g_DifferanceBetweenSigns * flag;
    }

    cout << inputString << endl;
    system("pause");
}
