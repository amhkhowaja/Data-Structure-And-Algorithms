#Simple Implementation of Tree having the feature of adding the treeNode , printing it and geting the level
class TreeNode:
    def __init__(self,data):
        self.data=data
        self.children=[]
        self.parent=None
    def add_child(self, child):
        child.parent=self
        self.children.append(child)
        return child
    def print_tree(self):
        spaces=" "*(self.get_level()*3) if self.parent is not None else ""
        print(spaces+self.data)
        for child in self.children:
            child.print_tree()
    def get_level(self):
        count=0

        while self.parent is not None:
            count+=1
            self=self.parent
        return count
 #Implementation
animal=TreeNode("Animal")
reptile=animal.add_child(TreeNode("Reptile"))
amphibian=animal.add_child(TreeNode("Amphibian"))
frog=amphibian.add_child(TreeNode("Frog"))
salaman =amphibian.add_child(TreeNode("Salaman"))
turtle=reptile.add_child(TreeNode("Turtle"))
snake=reptile.add_child(TreeNode("Snake"))
animal.print_tree() #Print the tree starting from the root Animal

