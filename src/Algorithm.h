template<typename ForwardIter, typename T>
ForwardIter algo_find( ForwardIter beg, ForwardIter end, T value) {
    while(beg != end) {
        if(*beg == value){
            return beg;
        }
        beg++;
    }
    return beg;
}