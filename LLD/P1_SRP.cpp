#include <bits/stdc++.h>
using namespace std;

// ❌ Violating SRP
class UserBad {
public:
    string name;

    void saveToDb() {
        cout << "Saving to DB" << endl;
    }

    void sendEmail() {
        cout << "Sending Email" << endl;
    }
};


// ✅ Following SRP
class User {
public:
    string name;
};

class UserRepository {
public:
    void saveToDb(const User& user) {
        cout << "Saving " << user.name << " to DB" << endl;
    }
};

class EmailService {
public:
    void sendEmail(const User& user) {
        cout << "Sending email to " << user.name << endl;
    }
};


int main() {

    User user;
    user.name = "Pradeep";

    UserRepository repository;
    repository.saveToDb(user);

    EmailService emailService;
    emailService.sendEmail(user);

    return 0;
}
