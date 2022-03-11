use std::{
    collections::{BinaryHeap, HashMap},
    fmt::Display,
    str::FromStr,
};

fn main() {
    let input = Input::from_str("MISSISSIPI RIVER").unwrap();

    let huffman = HuffmanCode::new(input);

    huffman.print();
}

#[derive(Eq, PartialEq, Clone)]
struct Node<T> {
    value: Option<T>,
    freq: i32,
    left: Option<Box<Node<T>>>,
    right: Option<Box<Node<T>>>,
}

impl<T> Ord for Node<T>
where
    T: PartialOrd + Eq + PartialEq,
{
    fn cmp(&self, other: &Node<T>) -> std::cmp::Ordering {
        other.freq.cmp(&self.freq)
    }
}

impl<T> PartialOrd for Node<T>
where
    T: Eq + PartialEq,
{
    fn partial_cmp(&self, other: &Node<T>) -> Option<std::cmp::Ordering> {
        Some(other.freq.cmp(&self.freq))
    }
}

impl<T> Node<T> {
    fn new(value: Option<T>, freq: i32) -> Node<T> {
        Node {
            value,
            freq,
            left: None,
            right: None,
        }
    }
}

struct DataFreq<T> {
    data: T,
    freq: i32,
}

struct Input<T>(Vec<DataFreq<T>>);

impl FromStr for Input<char> {
    type Err = String;

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let mut freq_count: HashMap<char, i32> = HashMap::new();
        for c in s.chars() {
            let count = freq_count.entry(c).or_insert(0);
            *count += 1;
        }

        let mut data_freq: Vec<DataFreq<char>> = Vec::new();
        for (c, count) in freq_count {
            data_freq.push(DataFreq {
                data: c,
                freq: count,
            });
        }

        Ok(Input(data_freq))
    }
}

struct HuffmanCode<T> {
    min_heap: BinaryHeap<Node<T>>,
}

impl<T> HuffmanCode<T> {
    fn new(data: Input<T>) -> HuffmanCode<T>
    where
        T: PartialOrd + Eq + PartialEq + Clone,
    {
        let mut min_heap = BinaryHeap::new();

        for elem in data.0 {
            min_heap.push(Node::new(Some(elem.data), elem.freq));
        }

        let mut left;
        let mut right;
        let mut top;

        while min_heap.len() > 1 {
            left = min_heap.pop().unwrap();
            right = min_heap.pop().unwrap();

            top = Node::new(None, left.freq + right.freq);
            top.left = Some(Box::new(left));
            top.right = Some(Box::new(right));

            min_heap.push(top);
        }

        HuffmanCode { min_heap }
    }

    fn print(&self)
    where
        T: PartialEq + Display,
    {
        self.print_codes(&mut String::new(), &self.min_heap.peek());
    }

    fn print_codes(&self, prefix: &mut String, node: &Option<&Node<T>>)
    where
        T: PartialEq + Display,
    {
        if node.is_none() {
            return;
        }
        let root = node.unwrap();

        if let Some(value) = &root.value {
            println!("{} - {}", value, prefix);
        }

        self.print_codes(&mut (prefix.to_owned() + "0"), &root.left.as_deref());
        self.print_codes(&mut (prefix.to_owned() + "1"), &root.right.as_deref());
    }
}
