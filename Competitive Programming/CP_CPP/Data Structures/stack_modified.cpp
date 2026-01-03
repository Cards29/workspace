// finding minimum in O(1)

stack<pair<int, int>> st;

// Add element
int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
st.push({new_elem, new_min});

// remove element
int removed_element = st.top().first;
st.pop();

// finding minimum
int minimum = st.top().second;
