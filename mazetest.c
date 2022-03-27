printf("count=%d up=%d right=%d left=%d down=% i=%d j=%d top=%d",stk[top].dir,stk[top].count,stk[top].up,stk[top].right,stk[top].left,stk[top].down,i,j,top);
if(stk[top].right==1){
        stk[top].right=0;
        continue;
      }
      if(stk[top].down==1){
        stk[top].down=0;
        continue;
      }
      if(stk[top].left==1){
        stk[top].left=0;
        continue;
      }
      if(stk[top].up==1){
        stk[top].up=0;
        continue;
      }
      printf("i=%d j=%d count=%d in=%d jn=%d\n",i,j,stk[top].count,stk[top+1].i,stk[top].j);
      stk[top].up=0;
      stk[top].down=0;
      stk[top].right=0;
      stk[top].left=0;
      