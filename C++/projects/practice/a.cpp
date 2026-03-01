#include <bits/stdc++.h>
using namespace std;

enum Role {
    AGENT,
    USER,
    TOOL
};

string roleToStr(Role role) {
    switch(role) {
        case AGENT: return "AGENT";
        case USER: return "USER";
        case TOOL: return "TOOL";
    }
    return "UNKNOWN";
}

struct Chunk {
    int start;
    int end;
    string text;
    Role role;
};


int main() {
    vector<Chunk> agentChunks = {
        {3600, 4000, "inventory for you."},
        {0, 600, "Hi there, thanks for calling"},
        {4600, 5200, "Great news! We have a 20"},
        {1200, 1800, "I help you find today?"},
        {600, 1200, "Sierra Outfitters. What gear can"},
        {6400, 6900, "Excellent, I'll add that to"},
        {5200, 5800, "liter waterproof daypack in stock."},
        {3200, 3600, "Perfect, let me search our"},
        {6900, 7200, "your cart right now."},
    };
    for(auto& chunk : agentChunks) chunk.role = Role::AGENT;
    vector<Chunk> userChunks = {
        {2300, 2800, "waterproof daypack for a short"},
        {5800, 6100, "That sounds perfect, I'll take"},
        {1800, 2300, "Hi! I'm looking for a"},
        {6100, 6400, "it."},
        {2800, 3200, "hike."},
    };
    for(auto& chunk : userChunks) chunk.role = Role::USER;
    vector<Chunk> toolcallChunks = {
        {4000, 4600, "search_inventory"},
    };
    for(auto& chunk : toolcallChunks) chunk.role = Role::TOOL;

    auto canMerge = [&] (const Chunk& c1, const Chunk& c2) {
        return c1.role == c2.role && c1.end <= c2.start;
    };

    auto printResult = [&] (const Chunk& chunk) {
       cout << "[ " << chunk.start << " - " << chunk.end <<" ] " << roleToStr(chunk.role) << " : " << chunk.text << endl; 
    };
    auto solve = [&] () {
        vector<Chunk> chunks;
        chunks.insert(chunks.end(), agentChunks.begin(), agentChunks.end());
        chunks.insert(chunks.end(), userChunks.begin(), userChunks.end());
        chunks.insert(chunks.end(), toolcallChunks.begin(), toolcallChunks.end());
        int n = chunks.size();
        sort(chunks.begin(), chunks.end(), [&](auto& a, auto& b) {
            if(a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });
        vector<Chunk> mergedChunks;
        for(int i = 0; i < n; i ++) {
            if(mergedChunks.empty() || !canMerge(mergedChunks.back(), chunks[i])) {
                mergedChunks.push_back(chunks[i]);
            } else {
                mergedChunks.back().end = max(mergedChunks.back().end,chunks[i].end);
                mergedChunks.back().text += " " + chunks[i].text;
            }
        }
        int lastEndTime = 0;
        for(int i = 0; i < n; i ++) {
            auto& chunk = chunks[i];
            if(i > 0) {
                if(chunk.start < lastEndTime) {
                   cout << "[!!! OVERLAP DETECTED !!! Offset: " << (lastEndTime - chunk.start) << "ms]" << endl;
                } else if(chunk.start > lastEndTime) {
                    cout << "[--- GAP " << chunk.start - lastEndTime << " ---]" << endl;
                }
            }
            printResult(chunk);
            lastEndTime = max(lastEndTime, chunk.end);
        }
        cout << "====================" << endl;
        for(auto chunk : mergedChunks) {
            printResult(chunk);
        }
    };
    solve();
    return 0;
}
