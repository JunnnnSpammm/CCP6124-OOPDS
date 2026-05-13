## Section 2: Review Questions and Exercises
### 1. What is a problem domain?

The problem domain is the set of real-world objects, activities, and behaviors that the software is designed to address. It represents the specific environment or "world" that the application will model.

### 2. How do you identify the potential classes in a problem domain description? Look at the following description of a problem domain:

#### A doctor sees patients in her practice. When a patient comes to the practice, the doctor performs one or more procedures on the patient. Each procedure performed has a description and a standard fee. As patients leave, they receive a statement that shows their name and address, as well as the procedures that were performed and the total charge for the procedures. Assume that you are creating an application to generate a statement that can be printed and given to the patient.

The standard technique is to perform a noun-phrase identification process. You read the description and highlight all the nouns. These nouns are the candidates for classes. You then filter them to remove duplicates, things that are better suited as attributes (data), and things that fall outside the scope of the software.

### 3. Identify all of the potential classes in this problem domain.

Doctor, Patient, Practice, Procedure, Description, Fee, Statement, Name, Address, Total charge

### 4. Refine the list to include only the necessary class or classes for this problem.

**Patient:** Necessary to store who the statement is for.

**Procedure:** Necessary to track what was done and the cost.

**Statement:** Necessary as the "container" or manager that aggregates the data and prints the final report.

### 5. Identify the responsibilities of the class or classes that you identified in step 4.

**Patient:** Know the patient's name and address.

**Procedure:** Know the procedure description and the standard fee.

**Statement:** Maintain a list of procedures performed; Calculate the total charges; Print/Format the statement details.