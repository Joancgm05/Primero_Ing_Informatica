library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity contador_tb is
--  Port ( );
end contador_tb;

architecture Behavioral of contador_tb is

    component contador
        Port (clk   : in STD_LOGIC;
              reset : in std_logic;
              ce    : in std_logic;
              count : out std_logic_vector (3 downto 0));  
    end component;
    
    signal clk   : std_logic := '0';
    signal reset : std_logic := '0';
    signal ce    : std_logic := '0';
    signal count : std_logic_vector (3 downto 0);

begin
    
    dut : contador 
    port map (clk   => clk,
              reset => reset,
              ce    => ce,
              count => count);
              
    -- Clock generation
    clk <= not clk  after 10 ns;
    
    stimuli : process
    begin 
    
        ce <= '0'; reset <= '1';
        wait for 100 ns; 
        reset <= '0';
        wait for 100 ns;
        ce <= '1';
        wait;
    end process;      
              
end Behavioral;