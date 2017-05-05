# Question 1

# 1.A)
def Q1A(x = '', y = '', z = '')
    if (x.empty?) && (y.empty?) && (z.empty?)
        return true
    else
        return false
    end
end

# 1.B)
def Q1B(x = '', y = '', z = '')
    str = x + y + z
    arr = str.split()
    return arr.join()
end

# 1.C
def Q1C(str = '')
    rts = str.reverse
    20.times { puts(rts) }
end

# Question 2
class MyString < String
    def shuffle?
        self.split('').shuffle.join
    end
end

# Question 3
person1 = { first: "Papa", last: "John" }
person2 = { first: "Mama", last: "Jane" }
person3 = { first: "Junior", last: "John" }
param = { father: person1, mother: person2, child: person3 }

# Question 4
def Q4()
    # Merge will create a new hash from the first and the second, 
    #  duplicated keys will take value from the second, so not 200 but 300.
    hash = { :"a" => 100, :"b" => 200 }.merge({ :"b" => 300 })
    hash[:b]
end

# Outputs
puts(Q1A())

puts(Q1B("Hello", "World", "!!"))

Q1C(Q1B("Hello", "World", "!!"))

puts ("Shuffled : " + MyString.new("Hello World !").shuffle?)

puts(param[:father][:first])

puts(Q4())