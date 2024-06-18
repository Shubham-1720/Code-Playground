from sympy import Symbol, Derivative
x = Symbol("x")
y = Symbol("y")
z = Symbol("z")
def div_vtr_field(vector): # Creating function to compute the divergence of the entered vector
  
  ptl_dvt_wrt_x = Derivative(vector[0],x).doit() # calculating partial derivative of the function w.r.t X
  ptl_dvt_wrt_y = Derivative(vector[1],y).doit() # calculating partial derivative of the function w.r.t Y
  ptl_dvt_wrt_z = Derivative(vector[2],z).doit() # calculating partial derivative of the function w.r.t Z
  divergence = ptl_dvt_wrt_x + ptl_dvt_wrt_y + ptl_dvt_wrt_z 
  
  print(f"Entered vector is {vector[0]}i + {vector[1]}j +  {vector[2]}k ")
  print()
  print(f"Divergence of the vector is \n {divergence}")
  

def main():
  print("This program is for computing divergence of vector field")
  print()
  print("Please enter the vector in indicated form e.g. [2*x**2, y**3, z**4]")
  equation = eval(input(""))
  div_vtr_field(equation)

if __name__=="__main__":
  main()