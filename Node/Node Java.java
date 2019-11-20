public class Node {
	
	private Node head, next;
	private int data;
	public int numOfNodes = 0;
	
	public Node() {
		//doNothing
	}
	
	//show entire list
	public void show() {
		Node temp;
		temp = head;
		if(temp == null) System.out.println("No list");
		while(temp != null) {
			System.out.printf("%d ", temp.data);
			temp = temp.next; 
		}
	}
	
	//insert as last node
	public void insert(int value) {
		Node temp = new Node();
		temp.data = value;
		if(head == null) {
			head = temp;
			head.next = null;
			temp = null;
		}else {
		temp = head;
		while(temp.next!=null) {
			temp = temp.next;
			}
		temp.next = new Node();
		temp.next.data = value;
		}
		numOfNodes++;
	}

	//insert as first node
	public void insertFirst(int value) {
		Node temp = new Node();
		temp.data = value;
		temp.next = head;
		head = temp;
		temp = null;
		numOfNodes++;
	}
	
	public void insertPos(int value, int pos) {
		Node temp = new Node();
		Node current = head;
		Node pre = current;
		if(pos > 1 && pos <= numOfNodes+1) {
			for(int i=1; i<pos; i++) {
				pre = current;
				current = current.next;
			}
			temp.data = value;
			pre.next = temp;
			temp.next = current;
			numOfNodes++;
		}else System.out.printf("\nNode insertion limits are: [1, %d]", numOfNodes+1);
		/*Line above is expressing that you can't insert a node
		unless as first or latest element*/
	}
	
	//delete all values that match
	public void delete(int value) {
		Node temp = new Node();
		Node current = new Node();
		temp = head;
		//actually check if item was deleted.
		boolean deleted = false; 
		if(temp == null) return;
		//check first
		if(temp.data == value) {
			head = temp.next;
			temp = null;
			numOfNodes--;
			deleted = true;
		}
		//check last
		temp = head;
		//go until (n-1) position
		while(temp.next.next != null) {
			temp = temp.next;
		}
		current = temp.next;
		if(current.data == value) {
			temp.next = null;
			current = null;
			numOfNodes--;
			deleted = true;
		}
		//check in-between 
		temp = head; 
		//go until final (n) position
		while(temp.next != null) {
			current = temp;
			temp = temp.next;
			if(temp.data == value) {
				current.next = temp.next;
				temp = temp.next;
				numOfNodes--;
				deleted = true;
			}
		}
		if(!deleted) {
			System.out.println("Can't find item.");
		}
	}
	public void deletePos(int pos) {
		Node temp = new Node();
		Node pre = new Node();
		temp = head;
		if(pos>1 && pos<= numOfNodes) {
			for(int i=1; i<pos; i++) {
				pre = temp;
				temp = temp.next;
			}
			pre.next = temp.next;
			temp = null;
			numOfNodes--;
		}else System.out.printf("\nNode deletion limits are: [1, %d]", numOfNodes);
	}
	
	//find item by value  //TODO: create a new list including those items
	public int find(int value) {
		Node temp = new Node();
		temp = head;
		int counter = 1;
		while(temp != null) {
			if(temp.data == value) {		
				break;
			}else {
				temp = temp.next;
				counter++;
			}
		}
		if(counter >= numOfNodes) counter = 0;
		return counter;
	}
}
