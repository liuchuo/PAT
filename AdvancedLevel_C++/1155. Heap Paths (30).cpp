#include <iostream>
#include <vector>

void path(const std::vector<int> &store, int start, std::string pre){
    if (start >= store.size())
        return;
    else if (start * 2 >= store.size()){
        pre = pre + " " + std::to_string(store.at(start));
        std::printf("%s\n", pre.substr(1).c_str());
        return;
    }
    path(store, start * 2 + 1, pre + " " + std::to_string(store.at(start)));
    path(store, start * 2, pre + " " + std::to_string(store.at(start)));
}

int main(){
    int nums;
    bool isMin = true, isMax = true;
    std::scanf("%d\n", &nums);
    std::vector<int> store = std::vector<int>(nums+1, 0);
    for (int i = 1; i <= nums; i++){
        std::scanf("%d", &store[i]);
    }
    for (auto i = 2; i < store.size(); i++){
        if (store[i / 2] < store[i])
            isMax = false;
        if (store[i / 2] > store[i])
            isMin = false;
    }
    path(store, 1, "");
    if (isMin)
        printf("Min Heap");
    else 
        printf("%s", isMax? "Max Heap" : "Not Heap");
}