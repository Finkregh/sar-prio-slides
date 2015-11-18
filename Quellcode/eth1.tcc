dev "eth1"{
    egress {
        class ( <$interactive_in> )
            if ip_tos_delay == 1 && tcp_sport == 22
            if ip_len < 256 && tcp_sport == 22;

        class ( <$other> ) if 1;

        htb () {
            class ( rate 200kbps, ceil 200kbps ) {
                $interactive_in = class ( rate 50kbps, ceil 100kbps ) {sfq;};
                $other = class ( rate 100kbps, ceil 140kbps ) {sfq;};
}}}}
