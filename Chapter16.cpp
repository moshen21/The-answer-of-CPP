#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
/*16_1
bool is_Palindrome(string & str);

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << ((is_Palindrome(str) == true) ? "Yes" : "No") << endl;
    return 0;
}

bool is_Palindrome(string & str) {
    int length = str.size();
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[length - 1 - i])
            return false;
    }
    return true;
}
*/
/*16_2
#include <cctype>
bool is_Palindrome(string & str);

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << ((is_Palindrome(str) == true) ? "Yes" : "No") << endl;
    return 0;
}

bool is_Palindrome(string & str) {
    string str_copy;
    for (int i = 0; i < str.size(); ++i) {
        if (isalpha(str[i]) || isdigit(str[i]))
            str_copy += tolower(str[i]);
    }
    int length = str_copy.size();
    for (int i = 0; i < str_copy.size() / 2; ++i) {
        if (str_copy[i] != str_copy[length - 1 - i])
            return false;
    }
    return true;
}
*/
/*16_3
int reduce(long ar[], int n);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long arr[n];
    cout << "Enter the " << n << " numbers(long): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = reduce(arr, n);
    cout << num;
    return 0;
}

int reduce(long ar[], int n) {
    sort(ar, ar + n);
    return unique(ar, ar + n) - ar;
}
*/
/*16_5
template <class T>
int reduce(T ar[], int n);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    long arr[n];
    cout << "Enter the " << n << " numbers(long): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = reduce(arr, n);
    cout << num << endl;
    int m;
    cout << "Enter m: ";
    cin >> m;
    string arrstr[m];
    cout << "Enter the " << m << " strings: " << endl;
    for (int i = 0; i < m; i++) {
        cin.get();
        getline(cin, arrstr[i]);
    }
    num = reduce(arrstr, m);
    cout << num;
    return 0;
}
template <class T>
int reduce(T ar[], int n) {
    sort(ar, ar + n);
    return unique(ar, ar + n) - ar;
}
*/
/*16_6
namespace C16_E6 {
class Customer {
private:
    long arrive;
    int processtime;

public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processtime; }
};
void Customer::set(long when) {
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
}  // namespace C16_E6
typedef C16_E6::Customer Item;

#include <cstdlib>
#include <ctime>
#include <queue>
const int MIN_PER_HR = 60;

bool newcustomer2(double x);

int main() {
    srand(time(0));
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    queue<Item> line;
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours;
    cout << "Enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;
    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++) {
        if (newcustomer2(min_per_cust)) {
            if (line.size() >= qs)
                turnaways++;
            else {
                customers++;
                temp.set(cycle);
                line.push(temp);
            }
        }
        if (wait_time <= 0 && !line.empty()) {
            temp = line.front();
            line.pop();
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time > 0) wait_time--;
        sum_line += line.size();
    }
    if (customers > 0) {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: " << (double)line_wait / served
             << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool newcustomer2(double x) { return (rand() * x / RAND_MAX < 1); }
*/
/*16_7
#include <cstdlib>
#include <ctime>
#include <iterator>
vector<int> Lotto(int n1, int n2);
int main() {
    vector<int> result;
    result = Lotto(51, 6);
    ostream_iterator<int, char> out_iter(cout, " ");
    copy(result.begin(), result.end(), out_iter);
    return 0;
}
vector<int> Lotto(int n1, int n2) {
    srand((unsigned)time(NULL));
    vector<int> all, result;
    for (int i = 1; i <= n1; ++i)
        all.push_back(i);
    for (int i = 1; i <= n2; ++i) {
        random_shuffle(all.begin(),all.end());
        result.push_back(all[0]);
    }
    sort(result.begin(), result.end());
    return result;
}
*/
/*16_8
#include <iterator>
void EnterFriends(vector<string>& vec_str);

int main() {
    vector<string> FriendsMat, FriendsPot, TotalFriends;
    cout << "Hi, Mat! Please enter your friends: \n";
    EnterFriends(FriendsMat);
    cout << "Hi, Pot! Please enter your friends: \n";
    EnterFriends(FriendsPot);
    TotalFriends.insert(TotalFriends.end(), FriendsMat.begin(),
                        FriendsMat.end());
    TotalFriends.insert(TotalFriends.end(), FriendsPot.begin(),
                        FriendsPot.end());
    ostream_iterator<string, char> out_iter(cout, "\n");
    copy(TotalFriends.begin(), TotalFriends.end(), out_iter);
    cout << endl;
    sort(TotalFriends.begin(), TotalFriends.end());
    TotalFriends.erase(unique(TotalFriends.begin(), TotalFriends.end()),
                       TotalFriends.end());
    copy(TotalFriends.begin(), TotalFriends.end(), out_iter);
    cout << endl;
    return 0;
}
void EnterFriends(vector<string>& vec_str) {
    string temp;
    getline(cin, temp);
    while (temp != "") {
        vec_str.push_back(temp);
        getline(cin, temp);
    }
}*/
/*16_9
#include <ctime>
#include <list>
int main() {
    int MAXSIZE = 1000000;
    vector<int> vi0(MAXSIZE);
    int temp;
    for (int i = 0; i < MAXSIZE; ++i) {
        temp = rand() / (RAND_MAX + 1) * MAXSIZE;
        vi0.push_back(temp);
    }
    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());
    clock_t start = clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    li.sort();
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    li.assign(vi0.begin(), vi0.end());
    start = clock();
    vi.assign(li.begin(), li.end());
    sort(vi.begin(), vi.end());
    li.assign(vi.begin(), vi.end());
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
*/
/*16_10
struct Review {
    string title;
    int rating;
    double price;
};

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool priceup(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool FillReview(shared_ptr<Review>& rr);
void ShowReview(const shared_ptr<Review>& rr);

int main() {
    vector<shared_ptr<Review>> books;
    shared_ptr<Review> temp;
    while (FillReview(temp)) books.push_back(temp);
    if (books.size() > 0) {
        cout << "Thank you. You entered the following " << books.size()
             << " ratings:\n"
             << "Price\tRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nPrice\tRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating up:\nPrice\tRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sorted by rating down:\nPrice\tRating\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);

        sort(books.begin(), books.end(), priceup);
        cout << "Sorted by price up:\nPrice\tRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        cout << "Sorted by price down:\nPrice\tRating\tBook\n";
        for_each(books.rbegin(), books.rend(), ShowReview);
    } else
        cout << "No entries. ";
    cout << "Bye.\n";
    return 0;
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else if (r1->title == r2->title && r1->rating == r2->rating &&
             r1->price < r2->price)
        return true;
    else
        return false;
}

bool worseThan(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    if (r1->rating < r2->rating)
        return true;
    else if (r1->rating == r2->rating && r1->price < r2->price)
        return true;
    else
        return false;
}

bool priceup(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(shared_ptr<Review>& rr) {
    rr = shared_ptr<Review>(new Review);
    cout << "Enter book title (quit to quit): ";
    getline(cin, rr->title);
    if (rr->title == "quit") return false;
    cout << "Enter book rating: ";
    cin >> rr->rating;
    if (!cin) return false;
    cout << "Enter book price: ";
    cin >> rr->price;
    if (!cin) return false;
    while (cin.get() != '\n') continue;
    return true;
}

void ShowReview(const shared_ptr<Review>& rr) {
    cout << rr->price << "\t" << rr->rating << "\t" << rr->title << endl;
}
*/