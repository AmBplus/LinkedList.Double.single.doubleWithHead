#include<iostream>
using namespace  std;
#include<cctype>

//============================================================================
// linked list
struct node  //
{
	int info;//
    node* next; //
};

class linkedList{ //
 public:
     node *first , *last ; //
     linkedList(){first = last = NULL;} //
        void show(); //
        node *createTempNode(int value ) ; //
        void insert() ;  //

};
node *linkedList::createTempNode(int value )  //
{
    node *temp = new node();
    temp->info = value ;
    temp->next = NULL ;
    return temp ;
}
void linkedList::insert() //
{
    int value ;
    cout << "\n\n\t \5Enter your Value = " ;
    cin >> value ;
    if (first==NULL)
    {
        first=last=createTempNode(value) ;
    }
    else
        {
          last=last->next = createTempNode(value);
          //last= createTempNode(value) ;
        }


  //   system("cls") ;
     cout << "\n\n\t******* successfully Aded ******* \n\n" ;
}
 void linkedList::show() //
      {

        node *temp = new node();
          temp = first ;
      if (temp==NULL)  //
      {

          cout << "\n\n\t \6 sorry but the list is empty \6\n\n\n" ;
      }
      else{

            cout << "\n\n \5 your list { " ;
        while(temp->info != NULL) //
        {
            cout << temp->info;
            //if (temp->next)
            if(temp==last)
            {
                break;
            }
            temp = temp->next ;
            cout << " , " ;

        }
             cout << " }\n\n" ;
      }
      }
//================================================================================================
// double linked list

struct doubleNode{ //
 doubleNode *LeftP , *RightP ; //
 int data ; //
}*temp1 ,*temp2; //
class doubleLinkedList{ //
 public:
     doubleNode *first , *last  ; //
     doubleLinkedList(){first = last = NULL;} //
        void show(); //
        doubleNode *doubleCreateTempNode(int value ) ; //
        void insert() ; //
        void DeleteLastNode();  //
        void insertNodeAfterX() ;  //
        void insertNodeBeforeX();  //
        void DeleteNode();  //
        void DeleteNodeBeforeX(); //
        void DeleteNodeAfterX(); //
        bool status() ; //
};
doubleNode *doubleLinkedList::doubleCreateTempNode(int value )
{
    doubleNode *temp = new doubleNode();
    temp->data = value ;
    if(first!=NULL)
    {
        last->RightP= temp ;
        temp->LeftP = last ;
        temp->RightP = first ;
        last = temp ;
        first->LeftP = last ;

    }
    return temp ;
}
bool doubleLinkedList::status()
{
    if(first == NULL)
    {
        cout << "\n\n\t Atention { Sorry , but your list is empty } \n" ;
        return false  ;
    }
    else
    {
        return true ;
    }
}
doubleNode *CreateNewLink()
{
    int data ;
    doubleNode *temp = new doubleNode();
    cout << "\n\n\t Enter data : " ;
    cin >> data ;
    temp->data = data ;
    return temp ;

}
void doubleLinkedList::insert()
{
    int value ;
    cout << "\n\n\t \5Enter your Value = " ;
    cin >> value ;
    if (first==NULL)
    {
       first= last = doubleCreateTempNode(value) ;
       first->RightP = last ;
       first->LeftP= last ;
       last->RightP= first ;
       last->LeftP = first ;
    }
    else
        {
            doubleCreateTempNode(value);
        }
     cout << "\n\n\t******* successfully Aded ******* \n\n" ;
}
 void doubleLinkedList::show()
      {

        doubleNode *temp = new doubleNode();
        temp = first ;
      if (temp==NULL)
      {

          cout << "\n\n\t \6 Your the doubleLinkedList is empty \6\n\n\n" ;
      }
      else{

            cout << "\n\n \5 your list { " ;
        while(temp->data != NULL)
        {
            cout << temp->data;
            //if (temp->next)
            if(temp==last)
            {
                break;
            }
            temp = temp->RightP ;
            cout << " , " ;

        }
             cout << " }\n\n" ;
      }
      }
int x ;
 void doubleLinkedList::insertNodeAfterX()
 {

      cout << "\n\n\t enter number from  above List  " ;
      cout << "\n\n\t Enter X : " ;
      cin >> x ;
      doubleNode *temp = new doubleNode() ;
      temp = first ;

             while(temp->data != NULL)
        {
          if (temp->data == x )
          {
              if (first==last)
              {

                  last =CreateNewLink() ;
                  first->LeftP = last;
                  first->RightP = last ;
                  last->RightP = first ;
                  last->LeftP  = first ;

              }
              else if (temp==last && first!=last )
              {

                  temp1 = CreateNewLink();
                  last->RightP =temp1 ;
                  temp1->RightP = first ;
                  last = temp1 ;
                  first->LeftP = last ;

              }
            else {

                temp1 = temp->RightP ;  // set  temp right to temp1
                temp2 = CreateNewLink()  ; // create a new node
                temp->RightP = temp2 ; // temp right have a new value
                temp2->LeftP = temp ;
                temp2->RightP = temp1 ;
                temp1->LeftP =temp ;
            }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                bool flag ;
                cout << "\n continue : 1 \n Menu : 0 \n" ;
                cin>>flag ;
                if(flag)
                {
                      insertNodeAfterX() ;

                }


                break;
            }

        temp = temp->RightP ;

        }
 }

 void doubleLinkedList::insertNodeBeforeX()
 {
        cout << "\n\n\t enter number from  above List  " ;
      cout << "\n\n\t Enter X : " ;
      cin >> x ;
      doubleNode *temp = new doubleNode() ;
      temp = first ;

             while(temp->data != NULL)
        {
          if (temp->data == x )
          {
            if (first==last)
              {

                  first =CreateNewLink() ;
                  last->RightP = first ;
                  last->LeftP = first ;
                  first->RightP = last ;
                  first->LeftP = last ;

              }
              else if (temp==first && first!=last )
              {
                    temp1 = CreateNewLink();
                    first->LeftP = temp1 ;
                    temp1->RightP = first ;
                    first = temp1 ;
                    first->LeftP = last ;
                    last->RightP = first ;

              }
            else {

                temp1 = temp->LeftP ;  // set  temp right to temp1
                temp2 = CreateNewLink()  ; // create a new node
                temp1->RightP = temp2 ;
                temp2->LeftP = temp1 ;
                temp->LeftP = temp2 ;
                temp2->RightP = temp ;
            }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                bool flag ;
                cout << "\n continue : 1 \n Menu : 0 \n" ;
                cin>>flag ;
                if(flag)
                {
                      insertNodeBeforeX() ;
                }

                break;
            }

        temp = temp->RightP ;

        }
 }

 void doubleLinkedList::DeleteNode()
 {
     if (first==NULL)
     {
         cout << "\n\n\t\t The List is Empty " ;
     }
      else
      {
          cout << "\n\n\t enter number from  above List  " ;
          cout << "\n\n\t Enter X : " ;
          cin >> x ;
          doubleNode *temp = new doubleNode() ;
          temp = first ;

    while(temp->data != NULL)
        {
          if (temp->data == x )
          {
            if (first==last)
            {
                first=last = NULL ;
             }
             else if (temp==first && first!=last && first->RightP==last && first->LeftP==last)
              {
                  first = last ;
                  first->RightP = NULL ;
                  first->LeftP = NULL ;
                  last->RightP = NULL ;
                  last->LeftP = NULL ;
              }
             else if (temp==last && first!=last && last->RightP==first && last->LeftP==first)
                     {
                  last = first ;
                  first->RightP = NULL ;
                  first->LeftP = NULL ;
                  last->RightP = NULL ;
                  last->LeftP = NULL ;
            }
                else if (temp==last)
                {
                    temp1 = temp->LeftP ;
                    last = temp1 ;
                    last->RightP = first ;
                    first->LeftP = last ;
                }
                else if (temp==first)
                {
                     first=temp->RightP ;
                     last->RightP = first ;
                     first->LeftP = last ;
                }
                else
                {
                    temp->LeftP->RightP = temp->RightP ;
                    temp->RightP->LeftP = temp->LeftP ;
                }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                cout << "\n Continue = 1 \n Exit = 0 " ;
                cout << "\n Chocie  : " ;
                cin >> x ;
                if (x)
                {
                DeleteNode() ;
                }
                else
                {
                break;
                }
            }
        temp = temp->RightP ;
        }
      }
 }


 void doubleLinkedList::DeleteNodeAfterX()
 {
     if (first==last)
     {
         cout << "\n\n\t\t You can't delete any before and after X because before and after is null \n " ;
     }
      else
      {
          cout << "\n\n\t enter number from  above List  " ;
          cout << "\n\n\t Enter X : " ;
          cin >> x ;
          doubleNode *temp = new doubleNode() ;
          temp = first ;

    while(temp->data != NULL)
        {
          if (temp->data == x )
          {
            if (temp==last)
            {
                cout << "You can't After Before X , Because your Choice is last in The List" ;
            }
           else if(temp==first && temp->RightP == last && temp->LeftP == last)
            {
                  last = first ;
                  last->LeftP = last->RightP  =  first->LeftP = first->RightP = NULL ;
            }
           else if (temp->RightP == last)
              {
                  last= temp ;
                  temp->RightP = first ;
                  first->LeftP = last ;

              }

                else
                {
                    temp1 = temp->RightP->RightP ;
                    temp->RightP = temp1 ;
                    temp1->LeftP = temp ;
                }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                cout << "\n Continue = 1 \n Exit = 0 " ;
                cout << "\n Chocie  : " ;
                cin >> x ;
                if (x)
                {
                DeleteNodeBeforeX() ;
                }
                else
                {
                break;
                }
            }

        temp = temp->RightP ;

        }
      }
 }
 void doubleLinkedList::DeleteNodeBeforeX()
 {
      if (first==last)
     {
         cout << "\n\n\t\t You can't delete any before and after X because before and after is null \n " ;
     }
      else
      {
          cout << "\n\n\t enter number from  above List  " ;
          cout << "\n\n\t Enter X : " ;
          cin >> x ;
          doubleNode *temp = new doubleNode() ;
          temp = first ;

    while(temp->data != NULL)
        {
          if (temp->data == x )
          {
            if (temp==first)
            {
                cout << "You can't Delete Before X , Because your Choice is number one in The List" ;
            }
           else if(temp==last && temp->RightP == first && last->LeftP == first)
            {
                  first = last ;
                  last->LeftP = last->RightP  =  first->LeftP = first->RightP = NULL ;
            }
           else if (temp->LeftP == first)
              {
                  first= temp ;
                  temp->LeftP = last ;
                  last->RightP = first ;

              }

                else
                {
                    temp1 = temp->LeftP->LeftP ;
                    temp->LeftP = temp1 ;
                    temp1->RightP = temp ;
                }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                cout << "\n Continue = 1 \n Exit = 0 " ;
                cout << "\n Chocie  : " ;
                cin >> x ;
                if (x)
                {
                DeleteNodeBeforeX() ;
                }
                else
                {
                break;
                }
            }

        temp = temp->RightP ;

        }
      }
 }


void doubleLinkedList::DeleteLastNode()
{

    if(first==last)
    {
        first=last=NULL ;
        cout << "\n\n\n\t ->>>>>>>> List become empty <<<<<<<<-\n\n\n " ;
    }
    else
    {
        doubleNode *temp = new doubleNode ;
        temp = last->LeftP ;
        first->LeftP = temp ;
        temp->RightP = first ;
        last = temp ;
    }
}
//============================================================================================================================
//============================================================================================================================

class doubleLinkedListWithHead{ //
 public:
     doubleNode *first , *last , *head ; //
     doubleLinkedListWithHead(){first = last = head = NULL;} //
        void show(); //
        doubleNode *doubleCreateTempNode(int value ) ; //

        void insert() ; //
        void DeleteLastNode(); //
        void DeleteFirstNode(); //
        void DeleteNode(); //
        void InsertFirstNode(); //

        bool status() ; //
};
doubleNode *doubleLinkedListWithHead::doubleCreateTempNode(int value )
{
    doubleNode *temp = new doubleNode();
    temp->data = value ;
    if(first!=NULL)
    {
        head->LeftP = temp ;
        temp->RightP = head ;
        last->RightP = temp ;
        temp->LeftP = last ;
        last = temp ;
    }
    return temp ;
}
bool doubleLinkedListWithHead::status()
{
    if(first == NULL)
    {
        cout << "\n\n\t Atention { Sorry , but your list is empty } \n" ;
        return false  ;
    }
    else
    {
        return true ;
    }
}
void doubleLinkedListWithHead::InsertFirstNode()
{
    if (first==NULL)
    {
        insert() ;
    }
    else
    {
        temp1 = CreateNewLink();
        temp1->LeftP = head ;
        temp1->RightP = first ;
        first = temp1 ;
        head->RightP = first ;

    }
}
void doubleLinkedListWithHead::insert()
{
    int value ;
    cout << "\n\n\t \5Enter your Value = " ;
    cin >> value ;
    if (first==NULL)
    {
        head = new doubleNode() ;
       first= last = doubleCreateTempNode(value) ;
       head->RightP = first ;
       head->LeftP = last ;
       first->RightP = NULL;
       first->LeftP = head ;
       last->LeftP = NULL ;
       last->RightP = head ;
    }
    else
        {
            doubleCreateTempNode(value);
        }
     cout << "\n\n\t******* successfully Aded ******* \n\n" ;
}
 void doubleLinkedListWithHead::show()
      {

        doubleNode *temp = new doubleNode();
        temp = first ;
      if (temp==NULL) //
      {
          cout << "\n\n\t \6 Your the doubleLinkedListWithHead is empty \6\n\n\n" ;
      }
      else{


            cout << "\t \5 your list { " ;
        while(temp->data != NULL)
        {
            cout << temp->data;
            //if (temp->next)
            if(temp==last)
            {
                break;
            }
            temp = temp->RightP ;
            cout << " , " ;
        }
             cout << " }\n\n" ;
      }
      }

 void doubleLinkedListWithHead::DeleteNode()
 {
     if (first==NULL)
     {
         cout << "\n\n\t\t The List is Empty " ;
     }
      else
      {
          cout << "\n\n\t enter number from  above List  " ;
          cout << "\n\n\t Enter X : " ;
          cin >> x ;
          doubleNode *temp = new doubleNode() ;
          temp = first ;
    while(temp->data != NULL)
        {
          if (temp->data == x )
          {
            if (first==last)
            {
                head = first=last = NULL ;
             }
             else if (temp==first && first!=last && first->RightP==last && first->LeftP==last) //
              {
                  first = last ;
                  first->RightP = last ;
                  first->LeftP = head ;
                  last->RightP = head ;
                  last->LeftP = first ;
                  head->LeftP = last ;
                  head->RightP = last ;
              }
             else if (temp==last && first!=last && last->RightP==first && last->LeftP==first)
                     {
                  last = first ;
                  first->RightP = last ;
                  first->LeftP = head ;
                  last->RightP = head ;
                  last->LeftP = first ;
            }
                else if (temp==last)
                {
                temp1= temp->LeftP->RightP;
                temp1->RightP = head ;
                last = temp1 ;
                head->LeftP = temp1 ;
                }
                else if (temp==first)
                {
                     first=temp->RightP ;
                     head->LeftP = first ;
                     first->LeftP = head ;
                }
                else
                {
                    temp->LeftP->RightP = temp->RightP ;
                    temp->RightP->LeftP = temp->LeftP ;
                }
            cout << "\n\n\t Operation Is Done \n" ;
            break;
          }
            //if (temp->next)
            if(temp==last)
            {
                cout << "\n\n\t The Number you Enter not in the List Try Aqain " ;
                cout << "\n Continue = 1 \n Exit = 0 " ;
                cout << "\n Chocie  : " ;
                cin >> x ;
                if (x)
                {
                 DeleteNode() ;
                }
                else
                {
                break;
                }
            }
        temp = temp->RightP ;

        }
      }
 }

void doubleLinkedListWithHead::DeleteLastNode()
{

    if(first==last)
    {
        first=last=NULL ;
        cout << "\n\n\n\t ->>>>>>>> List become empty <<<<<<<<-\n\n\n " ;
    }
    else
    {
        doubleNode *temp = new doubleNode ;
        temp = last->LeftP  ;
        temp->RightP = head ;
        last = temp ;
        head->LeftP = last ;
    }
}

void doubleLinkedListWithHead::DeleteFirstNode()
{

    if(first==last)
    {
        first=last=NULL ;
        cout << "\n\n\n\t ->>>>>>>> List become empty <<<<<<<<-\n\n\n " ;
    }
    else
    {
        doubleNode *temp = new doubleNode ;
        temp = first->RightP  ;
        temp->LeftP = head ;
        first = temp ;
        head->RightP = first ;
    }
}
//========================================================================================================================
void menu() ;
void choiceMenu() ;
int ExitOrContinue() ;
void Design() ;


int main()
{
    // program started // made by amir massom beygi (NxC)  , hope enjoy it
    choiceMenu() ;

 return 0 ;

}//End main
void Design()
{
    cout << "\n\n\t             **********  WELCOME TO OUR PROGRAM  **************" ;

    cout << "\n\n\t             ***********   { AMIR MASSOM BEYGI }  **********" ;
    cout << "\n\n\t   \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4    i HOPE YOU ENJOY IT    \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n\n\n" ;

}
void StartExit()
{
    cout << "\n\t \1 For Use Program Enter 1 and For Exit Enter 0\n " ;
    cout << "\n\t \5 continue : 1 \n\t \5 Exit : 0\n" ;
    cout << "\t \6 Enter : " ;
    cin>>x ;
    system("cls") ;
    if(x==false)
    {
        exit(1) ;
    }

}
void menu()
{
    cout << "\n\t ===============================================================\n\n" ;
    cout << "\t \6. MENU\n" ;
    cout << "\t a)  insert node to SingLinkedList : " << endl;
    cout << "\t b)  Delete from SingLinkedList : " << endl;
    cout << "\t c)  Show SingleLinkedList: " << endl;
    cout << "\n\t ****************************************************************\n" ;
    cout << "\t d)  Insert node in End list (  Doubly - Linked List  )  " << endl;
    cout << "\t e)  Delete last node( Doubly - Linked List)  " << endl;
    cout << "\t f)  Show (Doubly - Linked List) " << endl;
    cout << "\t g)  Insert node after x ( Doubly - Linked List)" << endl;
    cout << "\t h)  Insert node before x (Doubly - Linked List)" << endl;
    cout << "\t i)  Delete node after x  (Doubly - Linked List) " << endl;
    cout << "\t j)  Delete node before x (Doubly - Linked List)  " << endl;
    cout << "\t k)  Delete node (Doubly - Linked List)  " << endl;
    cout << "\t ****************************************************************\n" ;
    cout << "\t L)  Insert node in start list ( Circular Doubly - Linked List with head node)  " << endl;
    cout << "\t m)  Insert node in End list ( Circular Doubly - Linked List with head node) " << endl;
    cout << "\t o)  Insert node in Empty list ( Circular Doubly - Linked List with head node) " << endl;
    cout << "\t p)  Delete node start list ( Circular Doubly - Linked List with head node)  " << endl;
    cout << "\t q)  Delete node End list ( Circular Doubly - Linked List with head node)  " << endl;
    cout << "\t r)  Delete One node ( Circular Doubly - Linked List with head node ) " << endl;
    cout << "\t s)  Show ( Circular Doubly - Linked List with head node ) " << endl;
    cout << "\n\t z)  EXIT  " << endl;

    cout << "\n\t \6  Your Choice : " ;

}
void choiceMenu()
{

     linkedList link ;
     doubleLinkedList doubleLink ;
     doubleLinkedListWithHead doublewithHead ;
     Design();

     while (true)
        {
        StartExit() ;
         menu() ;
         char a ;
         cin >> a ;
        a = tolower(a) ;
         system("cls");
    switch(a)
     {
    case 'a':
        {
            link.insert();
            break ;
        }
        case 'b':
        {
            break ;
        }
        case 'c':
            {
                link.show() ;
                break;
            }
//=========================================================================================
//=========================================================================================
//=========================================================================================
        case 'z':
            {
                exit(1) ;
            }
        case 'd':
            {
                doubleLink.insert() ;
                break ;
            }
        case 'e' :
            {
                if (doubleLink.status())
                {
                     doubleLink.show();
                     doubleLink.DeleteLastNode();
                     doubleLink.show() ;

                 }
                 break ;
            }

        case 'f' :
            {
                doubleLink.show();
                break ;
            }
        case 'g' :
            {
                 if (doubleLink.status())
                 {

                doubleLink.show();
                doubleLink.insertNodeAfterX();
                doubleLink.show();
                 }
                break ;
            }
        case 'h' :
            {
                 if (doubleLink.status())
                 {
                doubleLink.show();
                doubleLink.insertNodeBeforeX();
                doubleLink.show();
                 }
                break ;
            }
        case 'i' :
            {
                 if (doubleLink.status())
                 {

                doubleLink.show();
                doubleLink.DeleteNodeAfterX();
                doubleLink.show();

                 }
               break ;
            }
        case 'j' :
            {
                 if (doubleLink.status())
                 {
                doubleLink.show();
                doubleLink.DeleteNodeBeforeX();
                doubleLink.show();
                 }

                break ;
            }
        case 'k' :
            {
                 if (doubleLink.status())
                 {
                  doubleLink.show();
                  doubleLink.DeleteNode() ;
                  doubleLink.show();
                 }

                break ;
            }
 //=========================================================================================
 //=========================================================================================
 //=========================================================================================
         case 'l' :
            {


                  doublewithHead.show();
                  doublewithHead.InsertFirstNode() ;
                  doublewithHead.show();


                break ;
            }
              case 'm' :
            {
                  doublewithHead.show();
                  doublewithHead.insert();
                  doublewithHead.show();
                break ;
            }
             case 'o' :
            {

                  doublewithHead.show();
                  doublewithHead.insert();
                  doublewithHead.show();
                break ;
            }
              case 'p' :
            {
                 if (doublewithHead.status())
                 {
                  doublewithHead.show();
                  doublewithHead.DeleteFirstNode() ;
                  doublewithHead.show();
                 }

                break ;
            }
             case 'q' :
            {
                 if (doublewithHead.status())
                 {
                  doublewithHead.show();
                  doublewithHead.DeleteLastNode() ;
                  doublewithHead.show();
                 }

                break ;
            }
               case 'r' :
            {
                 if (doublewithHead.status())
                 {
                  doublewithHead.show();
                  doublewithHead.DeleteNode();
                  doublewithHead.show();
                 }

                break ;
            }
             case 's' :
            {

                if (doublewithHead.status())
                {
                    doublewithHead.show() ;
                }

                break ;
            }
        default:
            {
                system("cls") ;
                cout << "\n\n\t unvalid chocie\n\n" ;
                  break;
            }
     }

        }
}







































































