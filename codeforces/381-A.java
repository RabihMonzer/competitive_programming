import java.util.*;

public class Main {

    public static void main(String[] args) {
    Scanner sc= new Scanner(System.in);

    int n = sc.nextInt();
    int sererja=0;
    int dima= 0;
    int counter=1;
    int[] cards= new int[n];

        for (int x = 0; x <n; x++) {
            cards[x]= sc.nextInt();
       }

        int i=0;
        int j=n-1;

        if (i==j)
         sererja=cards[i];

        while(i!=j)
        {
               if (cards[i]>cards[j] && counter %2 == 1) {
                sererja=sererja+cards[i];
                i++;
            }

               else if(cards[i]<cards[j] && counter %2 == 1) {
                sererja=sererja+cards[j];
                j--;
            }


            if (cards[i]>cards[j] && counter %2 == 0) {
                dima=dima+cards[i];
                i++;
            }

            else if(cards[i]<cards[j] && counter %2 == 0) {
                dima=dima+cards[j];
                j--;
            }


            counter++;
         if(i==j)
         {
             if (counter %2==1)
                 sererja=sererja+cards[i];
             else if(counter %2==0)
                 dima=dima+cards[i];
         }
            }

     System.out.print(sererja+" "+dima);
    }
}