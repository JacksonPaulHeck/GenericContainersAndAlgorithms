template<typename ForwardIter, typename T>
ForwardIter algofind( ForwardIter beg, ForwardIter end, T value) {
    while(beg != end) {
        if(*beg == value){
            return beg;
        }
        beg++;
    }
    return beg;
}