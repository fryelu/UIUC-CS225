/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K & key) const
{
	return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node * subtree, const K & key) const
{
	if (subtree == NULL)
		return V();
	else if (key == subtree->key)
		return subtree->value;
	else
	{
		if (key < subtree->key)
			return find(subtree->left, key);
		else
			return find(subtree->right, key);
	}
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	//from class notes
    Node * y = t->right;
    t->right = y->left;
    y->left = t;
    
     t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
    y->height = max(heightOrNeg1(y->left), heightOrNeg1(y->right))+1;
   
    t=y;
    

}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	// Implemented for you:
	rotateLeft(t->left);
	rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    //from class notes.. almost the same as rotate left
    Node * y = t->left;
    t->left = y->right;
    y->right = t;


    t->height = max(heightOrNeg1(t->left), heightOrNeg1(t->right))+1;
    y->height = max(heightOrNeg1(y->left), heightOrNeg1(y->right))+1;
    
    t=y;
    
    
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	//almost the same as rotateleftright
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
	insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node* & subtree, const K & key, const V & value)
{

  	if(subtree == NULL) {
  		subtree = new Node(key, value);
  		subtree->height=0;
  	}

    else if(key < subtree->key){
    	insert(subtree->left, key, value);
    	int balance = heightOrNeg1(subtree->right)- heightOrNeg1(subtree->left);
    	int leftBalance = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
    	if(balance ==-2){
    		if(leftBalance ==-1)
    			rotateRight(subtree);
    		else
    			rotateLeftRight(subtree);
    	}
    }
    else if(key > subtree->key){
    	insert(subtree->right, key, value);
    	int balance = heightOrNeg1(subtree->right)- heightOrNeg1(subtree->left);
    	int rightBalance = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
    	if(balance ==2){
    		if(rightBalance ==1)
    			rotateLeft(subtree);
    		else
    			rotateRightLeft(subtree);
    	}
    }
    else
    	return;

    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right))+1;

}
