from sympy import Symbol, Derivative
x = Symbol("x")
y = Symbol("y")
z = Symbol("z")
gradient = []
def grad_sclr_field(fn): # Creating function to compute the gradient of the entered function
  
  ptl_dvt_wrt_x = Derivative(fn,x).doit() # calculating partial derivative of the function w.r.t X
  ptl_dvt_wrt_y = Derivative(fn,y).doit() # calculating partial derivative of the function w.r.t Y
  ptl_dvt_wrt_z = Derivative(fn,z).doit() # calculating partial derivative of the function w.r.t Z
  gradient.append(ptl_dvt_wrt_x)
  gradient.append(ptl_dvt_wrt_y)
  gradient.append(ptl_dvt_wrt_z)
  
  print(f"Entered function is \n{fn}")
  print(f"Gradient of the function is \n {gradient}")
  

def main():
  print("This program is for computing gradient of a scaler field")
  print("Please enter the data in equation from e.g. x**3*y**2 + 4*y**5")
  equation = eval(input(""))
  grad_sclr_field(equation)

if __name__=="__main__":
  main()