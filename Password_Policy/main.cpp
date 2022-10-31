#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Policy
{
protected:
    bool isChecked;

public:
    virtual void check(const string &arg_password)=0;
    bool getCheck() const
    {
        return isChecked;
    }
};

class LengthPolicy : public Policy
{
private:
    uint16_t minLength;
    uint16_t maxLength;

public:
    LengthPolicy(uint16_t minL)
    {
        minLength=minL;
        maxLength=255;
    }
    LengthPolicy(uint16_t minL, uint16_t maxL)
    {
        minLength=minL;
        maxLength=maxL;
    }
    void check(const string &arg_password)
    {   isChecked = false;

        if(arg_password.size() >= minLength && arg_password.size() <= maxLength)
        {
            isChecked = true;
        }
    }
};

class ClassPolicy : public Policy
{
private:
    uint16_t minClassCount;
public:
    ClassPolicy(uint16_t minClass)
    {
        minClassCount = minClass;
    }
    void check(const string &arg_password)
    {
        int digits,special_characters,letters,capital_letters,k;
        k = 0;
        digits = 0;
        special_characters = 0;
        letters = 0;
        capital_letters = 0;
        isChecked = false;
        for(int i = 0; i < arg_password.size(); i++)
        {
            if(isdigit(arg_password[i]))
            {
                digits++;
            }
            if(ispunct(arg_password[i]))
            {
                special_characters++;
            }
            if(isupper(arg_password[i]))
            {
                capital_letters++;
            }
            if(islower(arg_password[i]))
            {
                letters++;
            }
        }
        if(letters > 0)
        {
            k++;
        }
        if(capital_letters > 0)
        {
            k++;
        }
        if(digits > 0)
        {
            k++;
        }
        if(special_characters > 0)
        {
            k++;
        }
        if(k >= minClassCount)
        {
            isChecked = true;
        }

    }
};
class IncludePolicy : public Policy
{
private:
    char characterType;

public:
    IncludePolicy(char character)
    {
        characterType = character;
    }
    void check(const string &arg_password)
    {
        int digits,special_characters,letters,capital_letters,k;
        k = 0;
        digits = 0;
        special_characters = 0;
        letters = 0;
        capital_letters = 0;
        isChecked = false;
        for(int i = 0; i < arg_password.size(); i++)
        {
            if(isdigit(arg_password[i]))
            {
                digits++;
            }
            if(ispunct(arg_password[i]))
            {
                special_characters++;
            }
            if(isupper(arg_password[i]))
            {
                capital_letters++;
            }
            if(islower(arg_password[i]))
            {
                letters++;
            }
        }
        if(characterType == '0'&& digits > 0)
        {
            isChecked = true;
        }
        if(characterType == 'a' && letters > 0)
        {
            isChecked = true;
        }
        if(characterType == '$' && special_characters > 0)
        {
            isChecked = true;
        }
        if(characterType == 'A' && capital_letters>0)
        {
            isChecked = true;
        }
    }
};
class NotIncludePolicy : public Policy
{
private:
    char characterType;

public:
    NotIncludePolicy(char character)
    {
        characterType=character;
    }
    void check(const string &arg_password)
    {
        int digits,special_characters,letters,capital_letters,k;
        k = 0;
        digits = 0;
        special_characters = 0;
        letters = 0;
        capital_letters = 0;
        isChecked = false;
        for(int i = 0; i < arg_password.size(); i++)
        {
            if(isdigit(arg_password[i]))
            {
                digits++;
            }
            if(ispunct(arg_password[i]))
            {
                special_characters++;
            }
            if(isupper(arg_password[i]))
            {
                capital_letters++;
            }
            if(islower(arg_password[i]))
            {
                letters++;
            }
        }
        if(characterType== '0' && digits == 0)
        {
            isChecked = true;
        }
        if(characterType == 'a' && letters == 0)
        {
            isChecked = true;
        }
        if(characterType == '$' && special_characters == 0)
        {
            isChecked = true;
        }
        if(characterType == 'A' && capital_letters == 0)
        {
            isChecked = true;
        }
    }
};
class RepetitionPolicy : public Policy
{
private:
    uint16_t maxCount;

public:
    RepetitionPolicy(uint16_t max_value)
    {
        maxCount=max_value;
    }
    void check(const string &arg_password)
    {
        isChecked = true;
        int k = 1;
        for(int i = 0; i < arg_password.size(); i++)
        {
            if(arg_password[i] == arg_password[i + 1])
            {
                k++;
            }
            else
            {
                k = 1;
            }
            if(k > maxCount)
            {
                isChecked = false;
            }
        }
    }
};
class ConsecutivePolicy : public Policy
{
private:
    uint16_t maxCount;
public:
    ConsecutivePolicy(uint16_t max_value)
    {
        maxCount = max_value;
    }
    void check(const string &arg_password)
    {
        int k = 1;
        isChecked = true;
        for(int i = 0; i < arg_password.size(); i++)
        {
            if((arg_password[i] == arg_password[i+1] - 1) && ((arg_password[i] >= 'a' && arg_password[i] <= 'z') || (arg_password[i] >= 'A' && arg_password[i] <= 'Z') || (arg_password[i] >= '0' && arg_password[i]<='9')))
            {
                k++;
            }
            else
            {
                k = 1;
            }
            if(k > maxCount)
            {
                isChecked = false;
            }
        }
    }
};
string checkPassword(string arg_password, vector <Policy*> policies)
{
    int k = 1;
    for(int i = 0; i < policies.size(); i++)
    {
        policies[i] -> check(arg_password);
        if(policies[i] -> getCheck() == false)
        {
            k = 0;
        }
        if(k == 0)
        {
            return "NOK";
        }
    }
    return "OK";
}

int main()
{
    int number_of_policies;
    char input_character;
    uint16_t min_length, max_length, min_class_count, max_count;
    vector < Policy* > policies;
    string policy;
    string password;
    cin >> number_of_policies;
    for(int i = 0; i < number_of_policies; i++)
    {
        cin>>policy;
        if(policy == "length")
        {
            if(scanf("%hu %hu" , &min_length, &max_length) == 2)
            {
                policies.push_back(new LengthPolicy(min_length, max_length));
            }
            else
            {
                policies.push_back(new LengthPolicy(min_length));
            }
        }
        if(policy == "class")
        {
            cin >> min_class_count;
            policies.push_back(new ClassPolicy(min_class_count));
        }
        if(policy == "include")
        {
            cin >> input_character;
            policies.push_back(new IncludePolicy(input_character));
        }
        if(policy == "ninclude")
        {
            cin >> input_character;
            policies.push_back(new NotIncludePolicy(input_character));
        }
        if(policy == "repetition")
        {
            cin >> max_count;
            policies.push_back(new RepetitionPolicy(max_count));
        }
        if(policy == "consecutive")
        {
            cin >> max_count;
            policies.push_back(new ConsecutivePolicy(max_count));
        }
    }
    while(cin >> password)
    {
        cout << checkPassword(password,policies) << "\n";
    }
    return 0;
}