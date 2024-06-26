library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity contador is
    Port ( clk : in STD_LOGIC;
           reset : in STD_LOGIC;
           ce : in STD_LOGIC;
           count : out STD_LOGIC_VECTOR (3 downto 0));
end contador;

architecture Behavioral of contador is
    
    component ffD_reset
        Port (clk   : in STD_LOGIC;
              ce    : in STD_LOGIC;
              reset : in STD_LOGIC;
              d     : in STD_LOGIC;
              q     : out STD_LOGIC);
    end component;
    signal qa, qb, qc, qd: std_logic;
    signal da, db, dc, dd: std_logic;
    
begin

    unitA : ffD_reset
        port map (clk   => clk,
                  ce    => ce,
                  reset => reset,
                  d     => da,
                  q     => qa);
    unitB : ffD_reset
        port map (clk   => clk,
                  ce    => ce,
                  reset => reset,
                  d     => db,
                  q     => qb);
    unitC : ffD_reset
        port map (clk   => clk,
                  ce    => ce,
                  reset => reset,
                  d     => dc,
                  q     => qc);
    unitD : ffD_reset
        port map (clk   => clk,
                  ce    => ce,
                  reset => reset,
                  d     => dd,
                  q     => qd);
        
        dd <= not qd;
        dc <= not qa and (qc xor qd);
        db <= (not qb and qc and qd) or (qb and (not qc or not qd));
        da <= (qa and not qd) or (qb and qc and qd);
        
        count <= qa & qb & qc & qd; -- concatenación
--          count(0) <= qd;
--          count(1) <= qc:
--          count(2) <= qb;
--          count(3) <= qa;

end Behavioral;