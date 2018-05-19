 
fn main() {
    println!("cargo:rustc-link-lib=dylib=todolist");
    println!("cargo:rustc-link-search=native=/home/meox/Dropbox/rustc/todolist/");
}
