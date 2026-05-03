// 831. Masking Personal Information [M]
// LeetCode masking-personal-information

struct EmailNode {
    char firstC;
    char lastC;
    string domain;
};
struct PhoneNode {
    string localNumber;
    string countryCode;
};
class Solution {
public:
    string maskPII(string s) {
        auto isEmail = [&]() {
            return s.contains('@');
        };
        auto parseEmail = [&] () {
            auto pos = s.find('@');
            return EmailNode(
                s[0],
                s[pos - 1],
                s.substr(pos + 1)
            ); 
        };
        auto maskEmail = [&] (EmailNode& node) {
            string ans = "";
            ans += tolower(node.firstC);
            ans += "*****";
            ans += tolower(node.lastC);
            ans += '@';
            transform(node.domain.begin(), node.domain.end(), node.domain.begin(),[&] (char c) {
                return tolower(c);
            });
            ans += node.domain;
            return ans;
        };
        auto parsePhone = [&] () {
            int n = s.size();
            string localNumber = "";
            string countryCode = "";
            for(int i = n - 1; i >= 0; i --) {
                if(!isdigit(s[i])) continue;
                if(localNumber.size() < 10) {
                    localNumber += s[i];
                } else {
                    countryCode += s[i];
                }
            }
            reverse(localNumber.begin(), localNumber.end());
            reverse(countryCode.begin(), countryCode.end());
            return PhoneNode(
                localNumber,
                countryCode
            );
        };
        auto maskPhone = [&] (PhoneNode& node) {
            string last4Digit = node.localNumber.substr(node.localNumber.size() - 4);
            string prefix = "";
            if(node.countryCode.size() == 0) {
                prefix = "***-***-";
            } else if(node.countryCode.size() == 1) {
                prefix = "+*-***-***-";
            } else if(node.countryCode.size() == 2) {
                prefix = "+**-***-***-";
            } else if(node.countryCode.size() == 3) {
                prefix = "+***-***-***-";
            }
            return prefix + last4Digit;
        };
        if(isEmail()) {
            auto node = parseEmail();
            return maskEmail(node);
        } else {
            auto node = parsePhone();
            return maskPhone(node);
        }
        return "";
    }
};