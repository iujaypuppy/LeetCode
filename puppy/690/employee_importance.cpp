class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* employee = findEmployee(employees, id);
        if (NULL == employee) {
            return 0;
        }
        int res(employee->importance);
        for (vector<int>::iterator i(employee->subordinates.begin());
            i != employee->subordinates.end();
            i++) {
            res += getImportance(employees, *i);
        }
        return res;
    }
    
    Employee* findEmployee(vector<Employee*> employees, int id) {
        for (vector<Employee*>::iterator i(employees.begin()); i != employees.end(); i++) {
            if ((*i)->id == id) {
                return *i;
            }
        }
        return NULL;
    }
};
