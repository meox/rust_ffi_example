extern crate libc;
use std::ffi::CString;
use std::mem;


mod ctodo {
    use libc::{c_int, c_char};

    #[repr(C)]
    pub struct TODO_NODE {
        pub position: c_int,
        pub desc: [c_char; 128usize],
        pub next: *mut TODO_NODE
    }

    #[link(name = "todolist")]
    extern {
        pub fn create_todolist(list_name: *const c_char, list: *mut *mut TODO_NODE) -> c_int;
        pub fn add_element(desc: *const c_char, list: *mut TODO_NODE) -> c_int;
        pub fn show_list(list: *mut TODO_NODE) -> c_int;
    }
}

use ctodo::*;
pub struct TodoList {
    head: *mut TODO_NODE
}

impl TodoList {
    pub fn create_todolist(&mut self, s: &str) {
        unsafe {
            ctodo::create_todolist(CString::new(s).unwrap().as_ptr(), &mut self.head)
        };
    }

    pub fn add_element(&self, s: &str) {
        unsafe {
            ctodo::add_element(CString::new(s).unwrap().as_ptr(), self.head)
        };
    }

    pub fn show_list(&self) {
        unsafe {
            ctodo::show_list(self.head)
        };
    }
}


fn main() {
    println!("Hello, from Rust TodoList APP");
    let mut list = TodoList {
        head: unsafe { mem::uninitialized() }
    };
    
    list.create_todolist("MyList");
    list.add_element("rust binding");
    list.add_element("more test with pointer");
    list.add_element("add more utility function");
    
    list.show_list();
}
