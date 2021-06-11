#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>



/*
Task: H2
Family Name: Mahfouz
Given Name: Kareem
Matriculation number: 3085597
Uni-Email: kareem.mahfouz@stud.uni-due.de
Course of Studies: ISE CE
*/


void deleting();
void DisplayNodes();
using namespace std;
struct obstacle
{
  string Name;
  double x,y,dis;
    obstacle *next;
};
obstacle *head = nullptr;

obstacle* Sorting(obstacle *&head,obstacle *node)
{
    obstacle *temp=new obstacle;
    temp=head;

    if(head==NULL)
    {
    node->next=head;
    head =node;
    }
    else
    {
        if(node->dis<temp->dis)
        {

        node->next=head;
        head=node;
        }
        else
        {
            for(temp=head;temp!=NULL;temp=temp->next)
            {
                if(temp->next!=NULL)
                {
                      if(node->dis < temp->next->dis)
                    {
                        node->next=temp->next;
                        temp->next=node;

                        break;
                    }



                }
                else if(temp->next==NULL)
                    {
                        temp->next=node;
                        node->next=NULL;
                    }


            }


        }



    }
}



double Euclidian(obstacle *&p1 , obstacle *&p2)
{
    double d;
    d=sqrt( pow((p1->x - p2->x),2)+pow((p1->y - p2->y),2)  );
    return d;
}

void insertObstacle(string name, double x,double y)
{

   obstacle *newObstacle = new obstacle;
   newObstacle->Name = name;
   newObstacle->x = x;
   newObstacle->y = y;
   newObstacle->dis=sqrt(pow(x,2)+pow(y,2));
   Sorting(head,newObstacle);

}
//obstacle *//
obstacle *NearestObstacle(obstacle *head,obstacle *MyPointer)
{
    double distance;
    double minimum;
    obstacle *o=new obstacle;
    string name;
    obstacle *MovingPtr=new obstacle;
    minimum=50000;


    for(MovingPtr=head;MovingPtr!=NULL;MovingPtr=MovingPtr->next)
    {
    if(Euclidian(MovingPtr,MyPointer)!=0)
    {


        distance=Euclidian(MyPointer,MovingPtr);
         if(distance<minimum)
             {
                 o=MovingPtr;
                 minimum=distance;


             }


    }

}

return o;
}








void DisplayNodes(obstacle *&head)
{

obstacle *temp=new obstacle;

temp=head;

    do
    {

        cout<<"Obstacle "<<temp->Name<<"("<<fixed<<setprecision(2)<<temp->x<<" , "<<temp->y<<") , Distance:  "<<temp->dis<<" nearest to this: ";
        cout<<NearestObstacle(head,temp)->Name<<endl;



    temp=temp->next;

    }
    while(temp!=NULL);
}



void deleting(obstacle *&head)
{
obstacle *i=new obstacle;
obstacle *temp=new obstacle;
i=head;
for(i=head;i!=NULL;i=i->next)
{
    temp=i;
    head=head->next;
    cout<<temp->Name<<" ";
    delete temp;

}

}

int main()

{
    obstacle *MyPointer=new obstacle;

    int i=0;
    double d;
    string Test;
    string name;
    string Endword={"end"};
    double x,y;
    do
    {


        cout<<"string describing obstacle (\"end\" for end of input): "<<endl;
        cin>>Test;
    if(Endword.compare(Test)==0)
        break;
    else
        name=Test;

    cout<<"x and y coordinate:"<<endl;
    cin>>x>>y;
    insertObstacle(name,x,y);

    i++;

    }

while(Endword.compare(Test)!= 0);

//DisplayNodes(head);

//

//
DisplayNodes(head);
cout<<"Delete : " ;
deleting(head);
//

}
