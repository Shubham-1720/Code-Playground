from sympy import Symbol, Derivative
x = Symbol("x")
y = Symbol("y")
z = Symbol("z")
gradient = []
def curl_vtr_field(vector): # Creating function to compute curl of the vector field
  
  ptl_dvt_wrt_x_k = Derivative(vector[2],x).doit() # calculating partial derivative of the function w.r.t X
  ptl_dvt_wrt_y_k = Derivative(vector[2],y).doit() # calculating partial derivative of the function w.r.t Y
  ptl_dvt_wrt_y_i = Derivative(vector[0],y).doit() # calculating partial derivative of the function w.r.t Y
  ptl_dvt_wrt_z_i = Derivative(vector[0],z).doit() # calculating partial derivative of the function w.r.t Z
  ptl_dvt_wrt_x_j = Derivative(vector[1],x).doit() # calculating partial derivative of the function w.r.t X
  ptl_dvt_wrt_z_j = Derivative(vector[1],x).doit() # calculating partial derivative of the function w.r.t Z

  #curl components
  curl_x = ptl_dvt_wrt_y_k - ptl_dvt_wrt_z_j
  curl_y = ptl_dvt_wrt_z_i - ptl_dvt_wrt_x_k
  curl_z = ptl_dvt_wrt_x_j - ptl_dvt_wrt_y_i
  curl = [curl_x, curl_y, curl_z]
  
  print(f"Entered vector is {vector[0]}i + {vector[1]}j +  {vector[2]}k ")
  print()
  print(f"Curl of the vector is \n {curl}")
  print()
  print(f"Curl in vector form is {curl[0]}i +{curl[1]}j +{curl[2]}k")
  

def main():
  print("This program is for computing curl of vector field")
  print("Please enter the vector in indicated form e.g. [2*x**2, y**3, z**4]")
  equation = eval(input(""))
  curl_vtr_field(equation)

if __name__=="__main__":
  main()