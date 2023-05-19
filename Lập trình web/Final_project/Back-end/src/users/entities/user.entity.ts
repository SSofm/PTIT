import {
  Entity,
  PrimaryGeneratedColumn,
  Column,
  OneToMany,
  OneToOne,
  JoinColumn,
} from 'typeorm';
import { Comment } from '../../comments/entities/comment.entity';
import { Cart } from '../../carts/entities/cart.entity';
import { Invoice } from '../../invoices/entities/invoice.entity';
@Entity()
export class User {
  @PrimaryGeneratedColumn()
  id: number;

  @Column()
  username: string;

  @Column()
  email: string;

  @Column()
  password: string;

  @Column()
  age: number;

  @Column({ default: false })
  isAdmin: boolean;

  @OneToMany(() => Comment, (comment) => comment.user, {
    // eager: true,
  })
  comments: Comment[];

  @OneToMany(() => Invoice, (invoice) => invoice.user)
  invoices: Invoice[];

  @OneToOne(() => Cart, {
    eager: true,
  })
  @JoinColumn()
  cart: Cart;
}
