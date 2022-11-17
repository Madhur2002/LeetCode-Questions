class Solution {
private:
    bool rec_overlap(int ax1, int ay1, int ax2, int ay2, int ax3, int ay3, int ax4, int ay4, int bx1, int by1, int bx2, int by2, int bx3, int by3, int bx4, int by4){
        if (ax4 == ax3 || ay4 == ay3 || bx3 == bx4 || by4 == by3)
            return false;
   
    // If one rectangle is on left side of other
       if (ax4 > bx3 || bx4 > ax3)
           return false;
 
    // If one rectangle is above other
       if (ay3 > by4 || by3 > ay4)
           return false;
 
       return true;
    } 
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ax3 = ax2;
        int ay3 = ay1;
        int ax4 = ax1;
        int ay4 = ay2;
        
        int bx3 = bx2;
        int by3 = by1;
        int bx4 = bx1;
        int by4 = by2;
        
        if(rec_overlap(ax1,ay1,ax2,ay2,ax3,ay3,ax4,ay4,bx1,by1,bx2,by2,bx3,by3,bx4,by4)){
            int x_coord = max(min(ax1,ax2),min(bx1,bx2)) - min(max(ax1,ax2),max(bx1,bx2));
            int y_coord = max(min(ay1,ay2),min(by1,by2)) - min(max(ay1,ay2),max(by1,by2));
            
            // cout<<x_coord<<" "<<y_coord<<endl;
            
            int area_overlapping = x_coord*y_coord;
            
            int rec_area = sqrt((ax1-ax4)*(ax1-ax4) + (ay1-ay4)*(ay1-ay4)) * sqrt((ax4-ax2)*(ax4-ax2) + (ay4-ay2)*(ay4-ay2)) + sqrt((bx1-bx4)*(bx1-bx4) + (by1-by4)*(by1-by4)) * sqrt((bx4-bx2)*(bx4-bx2) + (by4-by2)*(by4-by2));
            
            // cout<<rec_area;
            
            int rem_area = rec_area - area_overlapping;
            
            return rem_area;
        }
        else{
            int rec_area = sqrt((ax1-ax4)*(ax1-ax4) + (ay1-ay4)*(ay1-ay4)) * sqrt((ax4-ax2)*(ax4-ax2) + (ay4-ay2)*(ay4-ay2)) + sqrt((bx1-bx4)*(bx1-bx4) + (by1-by4)*(by1-by4)) * sqrt((bx4-bx2)*(bx4-bx2) + (by4-by2)*(by4-by2));
            return rec_area;
        }
        return 0;
    }
};
 