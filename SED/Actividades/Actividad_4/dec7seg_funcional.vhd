library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity dec7seg_funcional is
    Port ( bcd : in STD_LOGIC_VECTOR (3 downto 0);
           led : out STD_LOGIC_VECTOR (6 downto 0));
           
end dec7seg_funcional;

architecture Behavioral of dec7seg_funcional is

begin
-- segment encoinputg
--      0
--     ---
--  5 |    | 1
--     ---    <- 6
--  4 |    | 2
--     ---
--      3

    with bcd select
   led <= "1000000" when "0000",  --1
          "1111001" when "0001",  --2
          "0100100" when "0010",  --2
          "0110000" when "0011",  --3
          "0011001" when "0100",  --4
          "0010010" when "0101",  --5
          "0000010" when "0110",  --6
          "1111000" when "0111",  --7
          "0000000" when "1000",  --8
          "0010000" when "1001",  --9
          "0111111" when others;  ---
          

end Behavioral;