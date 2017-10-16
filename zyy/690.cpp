/*
// Employee info
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
    Employee *findEmployee(vector<Employee *> &employees, int id) {
        for (vector<Employee *>::iterator i(employees.begin());
             i != employees.end(); ++i) {
            if ((*i)->id == id) {
                return *i;
            }
        }

        return NULL;
    }
    int getImportance(vector<Employee*> employees, int id) {
        Employee *e(findEmployee(employees, id));
        if (e == NULL) {
            return 0;
        }

        int ret(e->importance);
        for (vector<int>::iterator i(e->subordinates.begin()); i != e->subordinates.end(); ++i) {
            ret += getImportance(employees, *i);
        }

        return ret;
    }
};
