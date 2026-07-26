class Node{
    int val;
    Node next;

    Node(int v){
        val=v;
        next=null;
    }
}

public class LinkedList {
    Node insertAtBeg(Node head, int val){
        Node ptr=new Node(val);
        if(head == null){
            head=ptr;
            return head;
        }
        ptr.next=head;
        head=ptr;
        return head;
    }

    Node append(Node head, int val){
        Node ptr=new Node(val);
        if(head == null){
            return ptr;
        }
        Node temp=head;

        while(temp.next != null){
            temp=temp.next;
        }
        temp.next=ptr;
        return head;
    }

    Node deleteFirst(Node head){
        if(head == null){
            return null;
        }
        // Node temp=head;
        head=head.next;
        // delete temp; 
        /*
        In Java, there is no delete keyword/function because Java has 
        automatic garbage collection.
        whenever you think "delete a node" in Java, usually you just 
        remove all references to it, and let the garbage collector 
        handle the memory.
        */
        return head;
    }

    Node deleteLast(Node head){
        if(head == null || head.next == null){
            return null;
        }

        Node temp=head;

        while(temp.next.next != null){
            temp=temp.next;
        }

        temp.next=null;
        return head;
    }

    void print(Node head){
        Node temp=head;
        while(temp != null){
            System.out.print(temp.val+" ");
            temp=temp.next;
        }
    }
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        Node head = null;

        for(int i=1;i<=5;i++){
            head=list.insertAtBeg(head, i);
        }

        head=list.deleteFirst(head);
        head=list.deleteLast(head);

        list.print(head);
    }
}