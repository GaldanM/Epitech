type 'a my_list =
	| Item of ('a * 'a my_list)
	| Empty

let lenght my_list =
	let rec lenght_loop = function
		| Item(_, next) -> 1 + lenght_loop(next)
		| Empty -> 0 in
	lenght_loop my_list	

let hd = function
| Item(head, _) -> head
| _ -> raise(Failure "hd")

let tl = function
| Item(_, next) -> next
| _ -> raise(Failure "tl")

let nth my_list i =
if (i < 0) then
	raise(Invalid_argument "List.nth")
else
	let rec loop_nth j = function
		| Item(head, next) ->
			if (j == 0) then
				head
			else
				loop_nth (j - 1) next
		| Empty -> raise(Failure "nth") in 
	loop_nth i my_list

let rev my_list =
	let rec rev_loop rev_list = function
		| Item (head, next) -> rev_loop (Item(head, next)) next
		| Empty -> rev_list in
	rev_loop Empty my_list

let append list_1 list_2 =
	let rec append_loop list_2 = function
		| Item(head, next) -> append_loop (Item(head, list_2)) next
		| Empty -> list_2 in
	append_loop list_2 (rev list_1)

let rev_append list_1 list_2 = append (rev list_1) list_2

let flatten my_list =
	let rec flatten_loop flatten_list = function
		| Item(head, next) -> flatten_loop(append flatten_list head) next
		| Empty -> flatten_list in
	flatten_loop Empty my_list

let rec iter func = function
	| Item(head, next) -> 	func head;
							iter func next
	| Empty -> ()

let map func =
	let rec map_loop ret_list func = function
		| Item(head, next) -> map_loop(Item(func head, ret_list)) func next
		| Empty -> (rev ret_list) in
	map_loop Empty func

let rec fold_left func my_list = function
	| Item(head, next) -> fold_left func (func my_list head) next
	| Empty -> my_list

let rec for_all func = function
	| Item(head, next) ->
		if (func head) then
			for_all func next
		else
			false
	| Empty -> true

let rec exists func = function
	| Item(head, next) ->
		if (func head) then
			true
		else
			exists func next
	| Empty -> false

let rec mem i = function
	| Item(head, next) ->
		if (head = i) then
			true
		else
			mem i next
	| Empty -> false

let rec memq i = function
	| Item(head, next) ->
		if (head == i) then
			true
		else
			mem i next
	| Empty -> false

let filter func my_list =
	let rec filter_loop list_filter func = function
		| Item(head, next) ->
			if (func head) then
				filter_loop (Item(head, list_filter)) func next
			else
				filter_loop list_filter func next
		| Empty -> list_filter in
	filter_loop Empty func my_list

let rec mem_assoc i = function
	| Item((j, _), next) -> 
		if (i = j) then
			true
		else
			mem_assoc i next
	| Empty -> false

let rec assoc i = function
	| Item((j, k), next) ->
		if (i = j) then
			k
		else
			assoc i next
	| Empty -> raise (Not_found)

let split my_list =
	let rec loop_split (a, b) = function
		| Item((j, k), next) -> loop_split (Item(j, a), Item(k, b)) next
		| Empty -> (a, b) in
	loop_split (Empty, Empty) (rev my_list)

