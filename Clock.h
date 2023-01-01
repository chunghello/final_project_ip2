
struct Clock{
public:
    Clock(){
        second=0;
        mili_second=0;
    }
    void add(){
        mili_second++;
        if(mili_second==60){
            second++;
            mili_second=0;
        }
    }
    float get_time(){return second+(float)mili_second/60;}
    float get_second(){return (float)second;}
    float get_mili_second(){return (float)mili_second;}
private:
    int second;
    int mili_second;
};
