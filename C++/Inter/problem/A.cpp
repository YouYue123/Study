We have a large file containing a list of contacts sorted alphabetically by name. Write a function to look up a phone number by name?

Alfa 123-456-01 /n
Bravo 123-456-02 /n
Charlie xxx-xxx-12 /n
Char lie 123-456-03/n
Charliea  123-456-04
1000000k size Charliec  123-456-05
Charlied  123-456-06

Delta 123-456-04

100k items but short enough to fit in memory

search("Charlie") returns "123-456-03"

files to find few names in a few names

// 1. Binary search
// 2. Trie

//Trie we need to build the tree first, then we can search in O(n) time
// Building the Trie will take O(n * m) time where n is the number of contacts and m is the average length of the names
// Trie can also do a disk based search, but it will be slower than a binary search on a sorted list 
1(hash_map) * O(n) which n is the size of search string (Trie)



// This N is the size of the contacts list
(log(N)) (Binary search)
 
/// Only called few times, so we can use binary search instead of Trie
/// Since Trie is too costly to build and maintain for this use case


using namespace std;

"123"

pair<string, string> readLine() {
    // read(10)
    // 1e3 is long enough
    // we read both before and after
    auto a = read(1e3 * 2);
    // [first(imcompl), second(must be valid), third, ...]
    auto s = a.split('/n')[1];
    // convert this s into pair<string, string>
    vector<string> list = s.split(" ");
    return { list[0], list[1] };
}
// abds(left) / n
string search(string fileName, string name) {
    // we use file offest to do binary search
    // open()
    // close()
    // read(numOfBytes) returns number of bytes
    // seek(int offset) moves the file cursor to specific 
    // seek(offset); read(size); this will seek offset first then read the size from seek
    // getSize(): will get the size of the file
    try {
        auto handler = open(fileName);
        long long left = 0, right = getSize(fileName); // total byte size of file
        while(left < right) {
            // (left + right) / 2
            long long mid = left + ((right - left) / 2);
            seek(mid);
            if(readLine().first >= name) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        seek(left);
        auto& item = readLine();
        close(handler);
        if(item.first == name) return "No found";
        else return item.second;
    } catch(e) {
        
    }
}
