#include <bits/stdc++.h>
using namespace std;

// 1912. Design Movie Rental System [H]
// LeetCode design-movie-rental-system

struct Item {
    int shop;
    int price;
    int movie;
    bool operator < (const Item& other) const {
        if(price != other.price) return price < other.price;
        if(shop != other.shop) return shop < other.shop;
        return movie < other.movie;
    };
};
class MovieRentingSystem {
private:
    unordered_map<int, vector<Item>> movie_to_item_dict;
    map<pair<int, int>, int> shop_movie_to_price_dict;
    set<Item> rented;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            movie_to_item_dict[movie].emplace_back(shop, price, movie);
            shop_movie_to_price_dict[make_pair(shop, movie)]= price;
        }
        for(auto& item : movie_to_item_dict) {
            sort(item.second.begin(), item.second.end());
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto& item : movie_to_item_dict[movie]) {
            if(rented.contains(item)) {
                continue;
            }
            ans.push_back(item.shop);
            if(ans.size() == 5) break;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto p = make_pair(shop, movie);
        rented.insert(Item(shop, shop_movie_to_price_dict[p], movie));
    }
    
    void drop(int shop, int movie) {
        auto p = make_pair(shop, movie);
        rented.erase(Item(shop, shop_movie_to_price_dict[p], movie));
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto& item : rented) {
            ans.push_back({ item.shop, item.movie });
            if(ans.size() == 5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */